#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>

using namespace std;

void generateFileWithFormat(int numberOfLines, int sizeRam, int maxValue) {
    ofstream file("./data-file/instructions.txt");

    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }

    srand(time(0));

    for (int i = 0; i < numberOfLines; ++i) {
        char instructionType = (rand() % 2 == 0) ? 'R' : 'W'; // Randomly choose between 'R' and 'W'
        int ramIndex = rand() % (sizeRam + 1); // Generate a random number for RAM index
        int value = rand() % (maxValue + 1); // Generate a random number for the value (for 'W' instructions)

        file << instructionType << " " << ramIndex;
        
        if (instructionType == 'W') {
            file << " " << value;
        }
        
        file << endl;
    }

    file.close();

    cout << "File created successfully." << endl;
}

int main() {
    int numberOfLines, sizeRam, maxValue;

    cout << "| Generate Test |" << endl;

    cout << "Enter the number of lines: ";
    cin >> numberOfLines;

    cout << "Enter the size of RAM: ";
    cin >> sizeRam;

    cout << "Enter the maximum value: ";
    cin >> maxValue;

    generateFileWithFormat(numberOfLines, sizeRam, maxValue);

    return 0;
}
