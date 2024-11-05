@echo off
g++ ./generator-files/create-file-ram.cpp
.\a.exe
g++ ./generator-files/generate-test.cpp
.\a.exe
del .\a.exe
