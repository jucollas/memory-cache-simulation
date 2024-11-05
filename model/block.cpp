#include "block.h"

Block::Block() : valid(false), dirtyBit(false), tag(0), high(0), lower(0), data(BLOCK_SIZE, 0){}

bool Block::isValid() {
    return valid;
}

bool Block::getDirtyBit() {
    return dirtyBit;
}

int Block::getTag() {
    return tag;
}

int Block::getLower() {
    return lower;
}

int Block::getHigh() {
    return high;
}

std::vector<int> Block::getData(){
    return this->data;
}

void Block::setValid(bool value) {
    valid = value;
}

void Block::setDirtyBit(bool value) {
    dirtyBit = value;
}

void Block::setTag(int tag) {
    this->tag = tag;
}

void Block::setRange(int address) {
    this->lower = address - (address & ((1 << OFFSET_SIZE) - 1));
    this->high = this->lower + BLOCK_SIZE;
}

void Block::setAllData(std::vector<int> data){
    this-> data = data;
}

void Block::setOneData(int offset, int data){
    this->data[offset] = data;
}

bool Block::operator==(const Block& other) const {
    return tag == other.tag;
}

void Block::print() const {
    std::cout << "| " << std::setw(7) << "Valid" << " | " << std::setw(9) << "DirtyBit" << " | " 
              << std::setw(4) << "Tag" << " | " << std::setw(14) << "Range" << " |" << std::endl;

    std::cout << "| " << std::setw(7) << std::setfill('-') << "" << " | " 
              << std::setw(9) << std::setfill('-') << "" << " | " 
              << std::setw(4) << std::setfill('-') << "" << " | " 
              << std::setw(14) << std::setfill('-') << "" << " |" << std::setfill(' ') << std::endl;

    std::cout << "| " << std::setw(7) << std::left << valid << " | " 
              << std::setw(9) << std::left << dirtyBit << " | " 
              << std::setw(4) << std::left << tag << " | " 
              << "[" << std::setw(5) << std::left << high << ".." << std::setw(5) << std::left << lower << "] |" << std::endl;

    std::cout << "Data:" << std::endl << "[";
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i < data.size() - 1) {
            std::cout << ", ";
        }
        if (i == (data.size()/2) - 1){
            std::cout << std::endl << " ";
        }
    }
    std::cout << "]" << std::endl;

    /*for(int i = 0; i < (data.size()/2) * 3; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;*/
}



