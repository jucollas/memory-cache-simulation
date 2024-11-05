#ifndef PERFORMANCE_REPORT
#define PERFORMANCE_REPORT

#include <vector>
#include <iostream>
#include <iomanip>

class PerformanceReport{
    private:
        int missRead, ordersRead;
        int missWrite, ordersWrite;
        std::vector<int> reportReadMiss, reportWriteMiss;
        std::vector<int> reportReadOrder, reportWriteOrder;
    public:
        PerformanceReport();

        void increaseMissRead();
        void increaseOrdersRead();
        void increaseMissWrite();
        void increaseOrdersWrite();

        void evaluateReport();
        void generateReport();
        void generateTable();
};

#endif