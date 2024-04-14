#ifndef FILES_H
#define FILES_H
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "lexical.h"
using namespace std;
class Files // Files class
{
private: 
    string files; // File name

public:
    string read(const string &files) const; // Read the file
    void write(const string &files, const string &output) const; // Write to the file
};
#endif