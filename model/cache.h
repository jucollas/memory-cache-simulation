#ifndef CACHE_H
#define CACHE_H

#include "memory.h"
#include "block.h"
#include "replacement-policy.h"
#include "performance-report.h"
#include <cmath>
#include <iostream>

using namespace std;

class Cache : public Memory {
    private:
        int size, ways, depth;
        Memory* lowerMemory;
        ReplacementPolicy* replacementPolicy;
        PerformanceReport* performanceReport;
        vector<vector<Block>> blocks;

    public:
        Cache(Memory* lowerMemory, ReplacementPolicy* replacementPolicy, int size, int ways);

        vector<int> readMany(int address) override;
        int readOne(int address) override;
        void writeMany(int address, vector<int> data) override;
        void writeOne(int address, int data) override;
        void printSet(int index);
        void Report();
};

int miss(vector<Block>& set, Memory* lowerMemory, ReplacementPolicy* replacementPolicy, int address, int tag, int index);
int searchCard(vector<Block>& set, int tag);
int isHit(vector<Block>& set, int tag);
int thereIsemptySpace(vector<Block>& set);
void loadIntoCache(Block& block, Memory* memory, int address, int tag);
void DecomposeAddress(int address, int depth, int& tag, int& index, int& offset);

#endif
