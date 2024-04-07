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
#include "symbol.h"

using namespace std;

symbol::symbol(const string& syms, const string& Classification, const string& value, const string& address, const string& segment) : syms(syms), Classification(Classification), value(value), address(address), segment(segment)
{
    
}

void symbolTable::addSymbol(const string& syms, const string& Classification, const string& value, const string& address, const string& segment)
{
    symbols.push_back(symbol(syms, Classification, value, address, segment));
}

symbolTypes symbolTable::symMap(const string& lexeme, const string& tokenType)
{
    if(tokenType == "RESERVED WORD")
    {
        if(lexeme == "CLASS" || lexeme == "class") return symbolTypes::ClassType;
        if(lexeme == "DO"|| lexeme == "do") return symbolTypes :: keyType;
        if(lexeme == "THEN" || lexeme == "then") return symbolTypes ::keyType;
        if(lexeme == "CALL" || lexeme == "call") return symbolTypes ::keyType;
        if(lexeme == "VAR" || lexeme == "var") return symbolTypes::keyType;
        if(lexeme == "WHILE" || lexeme == "while") return symbolTypes::keyType;
        if(lexeme == "IF" || lexeme == "if") return symbolTypes::keyType;
        if(lexeme == "ODD" || lexeme == "odd") return symbolTypes::keyType;
        if(lexeme == "PROCEDURE" || lexeme == "procedure") return symbolTypes::keyType;
    }
    return symbolTypes::otherType;
}

symbolstates symbolTable::nextState(symbolstates currentState, symbolTypes input)
{
    return static_cast<symbolstates>(SymTable[static_cast<int>(currentState)][static_cast<int>(input)]);
}

vector<symbol>& symbolTable::getSymbols()
{
    return symbols;
}

symbolTable::symbolTable()
{
    SymConfig();
}

void symbolTable::SymConfig()
{
    

}





