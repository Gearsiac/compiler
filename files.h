#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream> // Add missing include directive for 'fstream'
#include <sstream>
using namespace std;

class File{
    private:
    string fileName;
    string fileContent;
    public:
    File(const string& fileName) {
        this->fileName = fileName;
    }
    void readFile() {
        ifstream file(fileName);
        if (file.is_open()) {
            file >> noskipws; // Read everything including whitespace
            char c;
            while (file >> c) {
                fileContent += c;
            }
            file.close();
        }
    }
    void printFile() {
        cout << fileContent;
    }
};
#endif