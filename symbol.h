#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
#include <iostream>
#include <iomanip>
#include "lexical.h"
#include "States.h"
#include "Files.h"
 
using namespace std;
const int Numstates = static_cast<int>(SymStateCount); // Number of states
const int Numintputs = static_cast<int>(SymTypeCount); // Number of inputs
const int NumSymbols = 300; // Number of symbols
struct symbol // Structure for symbol table
{
    string syms; // Symbol
    string Classification; // Classification
    string value; // Value
    int address; // Address
    string segment; // Segment
    symbol(const string& syms, const string& Classification, const string& value, const int address, const string& segment); // Constructor
    symbol() : syms(""), Classification(""), value(""), address(0), segment(""){} // Default constructor
};
class symbolTable
{
private:
    symbol symbols[NumSymbols]; // Array of symbols
    int SymTable[Numstates][Numintputs] = {}; // Symbol table
    void SymbolTableFSA(); // FSA configuration
    void addToTable(); // Add to table
    size_t position; // Position
    size_t SymbolCount; // Symbol count

public:
    symbolTable(); // Constructor
    size_t getSymbolCount() const; // Get symbol count
    symbolTypes symMap(const Tokens& token); // Symbol map
    symbolstates ReadRowsAndCollums(symbolstates currentState, symbolTypes input); // Get next state
    void addToSymbolTable(const string& syms, const string& Classification, const string& value, const int address, const string& segment); // Add to symbol table
    void symTable(const Tokens& token, Tokens* tokens, size_t tokenCount); // Symbol table
    void Setinput(const string& ins); // Set input
    symbol* getSymbols(); // Get symbols
};

#endif