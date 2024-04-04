#ifndef FILES_H
#define FILES_H
#include <iostream> 
#include <string>
#include <vector>
#include <iomanip> 
#include <fstream> 
#include <sstream>
#include "lexical.h"
using namespace std;

class files
{
    private:
    string files;

    public:
    string read(const string& filename) const;
    void write(const vector<Tokens>& tokens);
    void readlist();
};



#endif