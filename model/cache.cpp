#include "cache.h"

Cache::Cache(Memory* lowerMemory, ReplacementPolicy* replacementPolicy, int size, int ways) : lowerMemory(lowerMemory), replacementPolicy(replacementPolicy), size(size), ways(ways), depth(size / ways), performanceReport(new PerformanceReport()){
    // We initialize the block vector with the specified size and number of ways
    blocks.resize(depth);
    for (int i = 0; i < depth; ++i) {
        blocks[i].resize(ways);
        for (int j = 0; j < ways; ++j) {
            blocks[i][j] = Block();
        }
    }
}

void Cache::printSet(int index){
    this->replacementPolicy->printStatus(index);
    for (int i = 0; i < this->ways; ++i){
        blocks[index][i].print();
    }
}

vector<int> Cache::readMany(int address) {
    vector<int> ans;
    int blockIndex, tagReplace;
    int offset, index, tag;
    
    this->performanceReport->increaseOrdersRead();

    DecomposeAddress(address, this->depth, tag, index, offset);

    blockIndex = isHit(blocks[index], tag);
    if(blockIndex != -1){
        cout << "Cache hit!" << endl;
    }else{
        this->performanceReport->increaseMissRead();
        blockIndex = miss(blocks[index], this->lowerMemory, this->replacementPolicy, address, tag, index);
    }

    replacementPolicy->recordHit(index, tag);
    ans = blocks[index][blockIndex].getData();
    blocks[index][blockIndex].print();
    this->performanceReport->evaluateReport();
    return ans;
}

int Cache::readOne(int address) {
    int offset = address & ((1 << OFFSET_SIZE) - 1);
    return this->readMany(address)[offset];
}

void Cache::writeMany(int address, vector<int> data) {
    int blockIndex, tagReplace;
    int offset, index, tag;

    this->performanceReport->increaseOrdersWrite();

    DecomposeAddress(address, this->depth, tag, index, offset);
    blockIndex = isHit(blocks[index], tag);
    if(blockIndex != -1){
        cout << "Cache hit!";
    }else{
        this->performanceReport->increaseMissWrite();
        blockIndex = miss(blocks[index], this->lowerMemory, this->replacementPolicy, address, tag, index);
    }
    replacementPolicy->recordHit(index, tag);
    blocks[index][blockIndex].setAllData(data);
    blocks[index][blockIndex].setDirtyBit(true);
    this->performanceReport->evaluateReport();
}

void Cache::writeOne(int address, int data) {
    int blockIndex, tagReplace;
    int offset, index, tag;

    this->performanceReport->increaseOrdersWrite();

    DecomposeAddress(address, this->depth, tag, index, offset);

    blockIndex = isHit(blocks[index], tag);
    if(blockIndex != -1){
        cout << "Cache hit!" << endl;
    }else{
        this->performanceReport->increaseMissWrite();
        blockIndex = miss(blocks[index], this->lowerMemory, this->replacementPolicy, address, tag, index);
    }

    replacementPolicy->recordHit(index, tag);
    blocks[index][blockIndex].setOneData(offset, data);
    blocks[index][blockIndex].setDirtyBit(true);
    blocks[index][blockIndex].print();
    this->performanceReport->evaluateReport();
}

void Cache::Report(){
    this->performanceReport->generateReport();
    this->performanceReport->generateTable();
}

int miss(vector<Block>& set, Memory* lowerMemory, ReplacementPolicy* replacementPolicy, int address, int tag, int index){
    int blockIndex, tagReplace;
    cout << "Cache miss!";
    blockIndex = thereIsemptySpace(set);

    if(blockIndex != -1){
        cout << " -> Space empty" << endl;
    }else{
        cout << " -> Memory full";
        tagReplace = replacementPolicy->blockToReplace(index);
        cout << " -> Replacement Policy";
        blockIndex = searchCard(set, tagReplace);
        if(!set[blockIndex].getDirtyBit()){
            cout << " -> Dirty Bit ( 0 )" << endl;
        }else{
            cout << " -> Dirty Bit ( 1 )" << endl;
            lowerMemory->writeMany(set[blockIndex].getLower(), set[blockIndex].getData());
        }
    }
    loadIntoCache(set[blockIndex], lowerMemory, address, tag);
    return blockIndex;
}

int searchCard(vector<Block>& set, int tag){
    int i = 0, ans = -1;
    while(i < set.size() && ans == -1){
        if (set[i].getTag() == tag) {
            ans = i;
        }
        ++i;
    }
    return ans;
}

int isHit(vector<Block>& set, int tag){
    int i = 0, ans = -1;
    while(i < set.size() && ans == -1){
        if (set[i].isValid() && set[i].getTag() == tag) {
            ans = i;
        }
        ++i;
    }
    return ans;
}

int thereIsemptySpace(vector<Block>& set){
    int i = 0, ans = -1;
    while ( i < set.size() && ans == -1) {
        if (!set[i].isValid()) {
            ans = i;
        }
        ++i;
    }
    return ans;
}

void loadIntoCache(Block& block, Memory* memory, int address, int tag){
    block.setValid(true);
    block.setDirtyBit(false);
    block.setTag(tag);
    block.setRange(address);
    block.setAllData(memory->readMany(address));
}

void DecomposeAddress(int address, int depth, int& tag, int& index, int& offset){
    int num_bits_index = int(log2(depth));
    // we extract the parts of the address
    offset = address & ((1 << OFFSET_SIZE) - 1); 
    address >>= OFFSET_SIZE;
    index = address & ((1 << num_bits_index) - 1); 
    address >>= num_bits_index;
    tag = address;
}
