#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "files.h"
#include "lexical.h"

using namespace std;

string Files::read(const string &files) const
{
    ifstream file(files);
    if(!file.is_open())
    {
        cerr << "Error: Unable to open file " << files << endl;
        exit(1);
    }
    stringstream buffer;
    buffer << file.rdbuf();
    file.close(); // Close the file after reading
    return buffer.str();
}

void Files::write(const string &files, const string &output) const
{
    ofstream file(files);
    if(!file.is_open())
    {
        cerr << "Error: Unable to open file " << files << endl;
        exit(1);
    }
    file << output;
    file.close(); // Close the file after writing
}