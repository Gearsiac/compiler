#ifndef SYMBOL_H
#define SYMBOL_H
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
#include "States.h"
#include "FSA.h"
#include "Files.h"
 
using namespace std;

const int NsymC = static_cast<int>(SymStateCount);
const int NsymT = static_cast<int>(SymTypeCount);

struct symbol
{
    string lexeme;
    string tokenType;
    symbol(const string& lexeme, const string& tokenType) : lexeme(lexeme), tokenType(tokenType)
    {
    }
};
class symbolTable
{
private:
    vector<symbol> symbols;
    void add(const string& lexeme, const string& types);
    public:
    explicit symbolTable(FSA& fsa);
    void setInput(const string& lexeme);
    void tokenize(const string& lexeme);
    string keyword(const string& lexeme);
    vector<symbol>& getSymbols();

};
#endif