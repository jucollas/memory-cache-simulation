#ifndef REPLACEMENT_POLICY_H
#define REPLACEMENT_POLICY_H

class ReplacementPolicy{
    public:
        virtual void recordHit(int index, int tag) = 0;
        virtual int blockToReplace(int index) = 0;
        virtual ~ReplacementPolicy() {}
        virtual void printStatus(int index) = 0;
};

#endif