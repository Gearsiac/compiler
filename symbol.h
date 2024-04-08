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

const int Numstates = static_cast<int>(SymStateCount);
const int Numintputs = static_cast<int>(SymTypeCount);

struct symbol
{
    string syms;
    string Classification;
    string value;
    string address;
    string segment;
    symbol(const string& syms, const string& Classification, const string& value, const string& address, const string& segment);
};
class symbolTable
{
private:
    vector<symbol> symbols;
    int SymTable[Numstates][Numintputs] = {};
    void SymConfig();
    void addSymbol(const string& syms, const string& Classification, const string& value, const string& address, const string& segment);
    public:
    symbolTable();
    symbolTypes symMap(const Tokens& token);
    symbolstates getNextState(symbolstates currentState, symbolTypes input);
    void symbolize(const Tokens& token, const vector<Tokens>& tokens);
    vector<symbol>& getSymbols();

};
#endif