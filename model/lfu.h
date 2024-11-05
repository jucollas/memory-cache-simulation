#ifndef LFU_H
#define LFU_H

#include "replacement-policy.h"

#include <vector>
#include <utility>
#include <climits>
#include <iostream>

class LFU : public ReplacementPolicy{
    private:
        int depth, ways;
        std::vector<std::vector<std::pair<int, int>>> hitRecord;
    public:
        LFU(int depth, int ways);
        void recordHit(int index, int tag) override;
        int blockToReplace(int index) override;
        void printStatus(int index) override;
};

#endif