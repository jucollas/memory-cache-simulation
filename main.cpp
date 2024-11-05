#include "./model/memory-controller.h"

int main() {
    MemoryController controller(3072, 64, 4, "./data-file/ram-data.txt");
    controller.interactiveMode();
    /*cout << "Uploaded data" << endl;
    controller.loadFromFileToRAM("./data-file/ram-data.txt");
    cout << "Process" << endl;
    controller.processFile("./data-file/instructions.txt");
    controller.Report();
    controller.saveRAMToFile("./data-file/ram-data-post.txt");*/


    return 0;
}