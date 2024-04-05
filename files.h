#ifndef FILES_H
#define FILES_H
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <iterator>
#include <regex>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "lexical.h"
using namespace std;

class Files
{
    private:
    string files;

    public:
    string read(const string& filename) const;
    void write(const vector<Tokens>& tokens);
};



#endif