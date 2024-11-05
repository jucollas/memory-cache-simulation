#ifndef BLOCK_H
#define BLOCK_H

#include "constants.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Block {
private:
    bool valid, dirtyBit;
    int tag, high, lower;
    std::vector<int> data;

public:

    Block();

    bool isValid();
    bool getDirtyBit();
    int getTag();
    int getLower();
    int getHigh();
    std::vector<int> getData();

    void setValid(bool value);
    void setDirtyBit(bool value);
    void setTag(int tag);
    void setRange(int lower);
    void setAllData(std::vector<int> data);
    void setOneData(int offset, int data);

    void print() const;
    bool operator==(const Block& other) const;
};

#endif
