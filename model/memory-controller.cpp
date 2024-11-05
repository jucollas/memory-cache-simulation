#include "memory-controller.h"

MemoryController::MemoryController(int ramSize, int cacheSize, int cacheWays, string fileRam) 
: ram(ramSize), cache(&ram, new LFU(cacheSize / cacheWays, cacheWays), cacheSize, cacheWays), fileRam(fileRam) {
    this->loadFromFileToRAM(this->fileRam);
}

void MemoryController::processCommand(char type, int address, int data) {
    if (type == 'R') {
        cout << "Read " << "( address : " << address << " )" << endl;
        int result = cache.readOne(address);
        cout << "read data : | " << result << " |" << endl;
    } else if (type == 'W') {
        cout << "Write " << "( address : " << address << ", " << "data : " << data << " )" << endl;
        cache.writeOne(address, data);
    } else {
        cerr << "Tipo de operacion desconocido: " << type << endl;
    }
    /*for(int i = 0; i < 90; ++i) {
        cout << "-";
    }
    cout << std::endl;*/
    this->saveRAMToFile(this->fileRam);
}

void MemoryController::saveRAMToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < ram.getSize(); ++i) {
            outputFile << ram.readOne(i) << std::endl;
        }
        std::cout << "Datos de la RAM guardados en el archivo: " << filename << std::endl;
        outputFile.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura: " << filename << std::endl;
    }
}

void MemoryController::processFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        char type;
        int address, data;
        if (iss >> type && ((type == 'R' && iss >> address) || (type == 'W' && iss >> address >> data))) {
            processCommand(type, address, data);
        } else {
            std::cerr << "Error al procesar la línea: " << line << std::endl;
        }
    }
}

void MemoryController::loadFromFileToRAM(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string line;
    int address = 0;
    while (std::getline(inputFile, line) && address < ram.getSize()) {
        std::istringstream iss(line);
        int data;
        if (iss >> data) {
            ram.writeOne(address++, data);
        } else {
            std::cerr << "Error al procesar la línea: " << line << std::endl;
        }
    }
    cout << "Uploaded data" << endl;
    //this->ram.print();
}

void MemoryController::interactiveMode() {
    char operation;
    int address, data, index;
    std::string filename;
    while (true) {
        std::cout << "Operaciones disponibles: [R] Lectura, [W] Escritura, [P] Procesar Archivo, [M] Imprimir RAM, [A] Mostrar reporte, [C] imprimir bloque Cache, [Q] Salir" << std::endl;
        std::cout << "Ingrese la operación deseada: ";
        std::cin >> operation;
        if (operation == 'Q') {
            break;
        }
        switch (operation) {
            case 'R':
                std::cout << "Ingrese la dirección de lectura: ";
                std::cin >> address;
                //std::cout << "Valor leído: ";
                processCommand(operation, address, 0);
                /*for (int val : cache.readMany(address)) {
                    std::cout << val << " ";
                }*/
                std::cout << std::endl;
                break;
            case 'W':
                std::cout << "Ingrese la dirección de escritura: ";
                std::cin >> address;
                std::cout << "Ingrese el dato a escribir: ";
                std::cin >> data;
                processCommand(operation, address, data);
                //cache.writeOne(address, data);
                std::cout << "Escritura exitosa." << std::endl;
                break;
            case 'P':
                // Procesar comandos desde un archivo
                std::cout << "Ingrese el nombre del archivo a procesar: ";
                std::cin >> filename;
                processFile(filename);
                break;
            case 'M':
                std::cout << "Estado actual de la RAM" << std::endl;
                this->ram.print();
                break;
            case 'A':
                std::cout << "Reporte:" << std::endl;
                this->Report();
                break;
            case 'C':
                std::cout << "Bloque a imprimir: ";
                std::cin >> index;
                this->printCache(index);
                break;
            default:
                std::cerr << "Operación no válida. Intente nuevamente." << std::endl;
                break;
        }
    }
}

void MemoryController::Report() {
    //this->cache.updateReport();
    this->cache.Report();
}

void MemoryController::printCache(int index){
    this->cache.printSet(index);
}