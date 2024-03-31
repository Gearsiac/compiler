#ifndef READ_H
#define READ_H
#include <iostream>
#include <string>
#include <fstream>
#include "tokens.h"
using namespace std;

void readfile()
{
    ifstream file;
    file.open("Prgm.txt");
    if (!file)
    {
        cout << "File not found" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
void write()
{
    ofstream file;
    file.open("results.txt");
    if (!file)
    {
        cout << "File not found" << endl;
        return;
    }
    file << "Hello World" << endl;
    file.close();
}
#endif