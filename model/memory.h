#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

// Abstract Memory
class Memory {
    public:
        virtual int readOne(int address) = 0;
        virtual std::vector<int> readMany(int address) = 0;
        virtual void writeOne(int address, int data) = 0;
        virtual void writeMany(int address, std::vector<int> data) = 0;
        virtual ~Memory() {}
};

#endif