#include "performance-report.h"

PerformanceReport::PerformanceReport() : ordersRead(0), ordersWrite(0), missRead(0), missWrite(0) {}

void PerformanceReport::increaseOrdersRead(){
    this->ordersRead++;
}

void PerformanceReport::increaseOrdersWrite(){
    this->ordersWrite++;
}

void PerformanceReport::increaseMissRead(){
    this->missRead++;
}

void PerformanceReport::increaseMissWrite(){
    this->missWrite++;
}

void PerformanceReport::evaluateReport(){
    int nOrder = this->ordersRead + this->ordersWrite;
    if(nOrder % 10000 == 0){
        this->reportReadOrder.push_back(this->ordersRead);
        this->reportWriteOrder.push_back(this->ordersWrite);
        this->reportReadMiss.push_back(this->missRead);
        this->reportWriteMiss.push_back(this->missWrite);
    }
}

void PerformanceReport::generateReport() {
    int miss = this->missRead + this->missWrite;
    int orders = this->ordersRead + this->ordersWrite;

    std::cout << "+--------------------------+" << std::endl;
    std::cout << "| Cache Performance Report |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "| Total orders : " << std::setw(9) << std::right << orders << " |" << std::endl;
    std::cout << "| Hits         : " << std::setw(9) << std::right << (orders - miss) << " |" << std::endl;
    std::cout << "| Miss         : " << std::setw(9) << std::right << miss << " |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
}

void PerformanceReport::generateTable(){
    std::cout << std::left << std::setw(10) << "| Orders" << std::setw(10) << "| Read" << std::setw(10) << "| Hit" << std::setw(10) << "| Miss" << "||" << std::setw(9) << " Write" << std::setw(10) << "| Hit" << std::setw(10) << "| Miss" << "|\n";

    // Imprimir línea de separación
    std::cout << std::setw(10) << std::setfill('-') << "+" << std::setw(10) << "+" << std::setw(10) << "+"
                << std::setw(10) << "+" << std::setw(11) << "||" << std::setw(10)
                << "+" << std::setw(10) << "+" << std::setfill('-') << "+" << "\n";
    std::cout << std::setfill(' ');

    // Imprimir filas de datos
    for (size_t i = 0; i < this->reportReadOrder.size(); ++i) {
        std::cout << "| " << std::setw(8) << (this->reportReadOrder[i] + this->reportWriteOrder[i]) << "| "
                    << std::setw(8) << this->reportReadOrder[i] << "| "
                    << std::setw(8) << (this->reportReadOrder[i] - this->reportReadMiss[i]) << "| "
                    << std::setw(8) << this->reportReadMiss[i] << "|| "
                    << std::setw(8) << this->reportWriteOrder[i] << "| "
                    << std::setw(8) << (this->reportWriteOrder[i] - this->reportWriteMiss[i]) << "| "
                    << std::setw(8) << this->reportWriteMiss[i] << "|\n";
    }
}