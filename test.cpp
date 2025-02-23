#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Input and output file names
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    // Open the input file in read mode
    ifstream inputFile(inputFileName, ios::in);
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Open the output file in write mode
    ofstream outputFile(outputFileName, ios::out);
    if (!outputFile) {
        cerr << "Error: Unable to create output file." << endl;
        inputFile.close();
        return 1;
    }

    // Copy character by character
    char ch;
    while (inputFile.get(ch)) { // Read a character
        outputFile.put(ch);    // Write the character to the output file
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "File copied successfully." << endl;
    return 0;
}
