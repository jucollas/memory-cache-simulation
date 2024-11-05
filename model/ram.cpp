#include "ram.h"

RAM::RAM(int size) : data(size, 0) {}

std::vector<int> RAM::readMany(int address){
    if (address < 0 || address >= data.size()) {
        std::cerr << "Error: Accessing out of bounds memory\n";
    }
    std::vector<int> ans;
    int offset = address & ((1 << OFFSET_SIZE) - 1);
    address -= offset;

    for(int i = 0; i < BLOCK_SIZE; ++i){
        ans.push_back(data[address++]);
    }

    return ans;
}

int RAM::readOne(int address) {
    if (address < 0 || address >= data.size()) {
        std::cerr << "Error: Accessing out of bounds memory\n";
        return -1;
    }
    return data[address];
}

void RAM::writeMany(int address, std::vector<int> data) {
    if (address < 0 || address >= this->data.size()) {
        std::cerr << "Error: Accessing out of bounds memory\n";
        return;
    }
    int offset = address & ((1 << OFFSET_SIZE) - 1);
    address -= offset;
    for(int i = 0; i < BLOCK_SIZE; ++i){
        this->data[address++] = data[i];
    }
}

void RAM::writeOne(int address, int data) {
    if (address < 0 || address >= this->data.size()) {
        std::cerr << "Error: Accessing out of bounds memory\n";
        return;
    }
    this->data[address] = data;
}

void RAM::print() const {
    int columns = 6; // Número de columnas
    int rows = (data.size() + columns - 1) / columns; // Número de filas necesarias

    // Imprimir encabezados de las columnas
    std::cout << "|";
    for (int i = 0; i < columns; ++i) {
        int start = i * rows + 1;
        int end = std::min((i + 1) * rows, (int)data.size());
        std::cout << std::setw(5) << std::right << start << "-" << std::setw(6) << std::left << end << "|" << std::setw(12) << std::right << "dato" << "|";
    }
    std::cout << std::endl;

    // Imprimir separadores de columnas
    std::cout << "|";
    for (int i = 0; i < columns; ++i) {
        std::cout << std::setw(26) << std::setfill('-') << "|" << std::setfill(' ') ;
    }
    std::cout << std::endl;

    // Imprimir datos en columnas
    for (int i = 0; i < rows; ++i) {
        std::cout << "|";
        for (int j = 0; j < columns; ++j) {
            int index = j * rows + i;
            if (index < data.size()) {
                std::cout << std::setw(12) << std::right << index << "|" << std::setw(12) << std::right << data[index] << "|";
            } else {
                std::cout << std::setw(26) << "|" ;
            }
        }
        std::cout << std::endl;
    }
}

int RAM::getSize(){
    return data.size();
}

