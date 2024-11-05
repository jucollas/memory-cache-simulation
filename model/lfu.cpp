#include "lfu.h"

LFU::LFU(int depth, int ways) : ways(ways), depth(depth)  {
    hitRecord.resize(depth, std::vector<std::pair<int, int>>(ways, {INT_MAX, 0}));
}

void LFU::recordHit(int index, int tag) {
    for (int i = 0; i < ways; ++i) {
        if (hitRecord[index][i].first == tag) {
            hitRecord[index][i].second++;
            return;
        }
    }
    for (int i = 0; i < ways; ++i) {
        if (hitRecord[index][i].first == INT_MAX) {
            hitRecord[index][i].first = tag;
            hitRecord[index][i].second++;
            return;
        }
    }
}

int LFU::blockToReplace(int index) {
    int blockTag;
    int minFrequency = hitRecord[index][0].second;
    int blockIndex = 0;
    
    for(int i = 1; i < ways; ++i) {
        if (hitRecord[index][i].second < minFrequency) {
            minFrequency = hitRecord[index][i].second;
            blockIndex = i;
        }
    }
    blockTag = hitRecord[index][blockIndex].first;
    hitRecord[index][blockIndex].first = INT_MAX;
    return blockTag;
}

void LFU::printStatus(int index){
    std::cout << "counts : [";
    for(int i = 0; i < this->ways; ++i){
        std::cout << "way " << i << ": " << hitRecord[index][i].second << ", ";
    }
    std::cout << "]\n";
}
