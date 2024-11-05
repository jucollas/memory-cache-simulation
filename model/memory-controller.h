#ifndef MEMORY_CONTROLLER_H
#define MEMORY_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "ram.h"
#include "cache.h"
#include "lfu.h"

class MemoryController {
private:
    RAM ram;
    Cache cache;
    string fileRam;

public:
    MemoryController(int ramSize, int cacheSize, int cacheWays, string fileRam);

    void processCommand(char type, int address, int data);
    void saveRAMToFile(const std::string& filename);
    void processFile(const std::string& filename);
    void loadFromFileToRAM(const std::string& filename);
    void interactiveMode();
    void printCache(int index);
    void Report();
};

#endif
