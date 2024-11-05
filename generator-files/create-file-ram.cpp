#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>

using namespace std;

void createFileWithNumbers(int numberOfLines, int maxRange) {
    ofstream file("./data-file/ram-data.txt");

    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }

    srand(time(0));

    for (int i = 0; i < numberOfLines; ++i) {
        int number = rand() % (maxRange + 1); // Generate a random number in the range [0, maxRange]
        file << number << endl; // Write the number on a new line in the file
    }

    file.close();

    cout << "File created successfully." << endl;
}

int main() {
    int numberOfLines, maxRange;

    cout << "| Create file RAM |" << endl;

    cout << "Enter the number of lines: ";
    cin >> numberOfLines;

    cout << "Enter the maximum range of integers: ";
    cin >> maxRange;

    createFileWithNumbers(numberOfLines, maxRange);

    return 0;
}
