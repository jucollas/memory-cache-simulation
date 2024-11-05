#ifndef RAM_H
#define RAM_H

#include "constants.h"
#include "memory.h"
#include <iostream>
#include <iomanip>

class RAM : public Memory {
    private:
        std::vector<int> data;

    public:
        RAM(int size);

        int readOne(int address) override;
        std::vector<int> readMany(int address) override;
        void writeMany(int address, std::vector<int> data) override;
        void writeOne(int address, int data) override;
        int getSize();
        void print() const;
};

#endif
