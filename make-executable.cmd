@echo off
g++ .\model\block.cpp .\model\cache.cpp .\model\lfu.cpp .\model\ram.cpp .\model\memory-controller.cpp .\model\performance-report.cpp .\main.cpp -o .\main