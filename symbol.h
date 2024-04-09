#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
#include <vector>
#include <iostream>
#include <string>
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
    int address;
    string segment;
    symbol(const string& syms, const string& Classification, const string& value, const int address, const string& segment);
};
class symbolTable
{
private:
    vector<symbol> symbols;
    int SymTable[Numstates][Numintputs] = {};
    void SymConfig();
    void addToTable();
    size_t position = 0;

    public:
    symbolTable();
    symbolTypes symMap(const Tokens& token);
    symbolstates getNextState(symbolstates currentState, symbolTypes input);
    void addToSymbolTable(const string& syms, const string& Classification, const string& value, const int address, const string& segment);
    void symTable(const Tokens& token, vector<Tokens>& tokens);
    void Setinput(const string& ins);
    vector<symbol>& getSymbols();

};
#endif