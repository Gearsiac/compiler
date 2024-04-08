#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
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

symbolTypes symbolTable::symMap(const Tokens &token)
{
    if(token.lexeme == "RESERVED WORD")
    {
        if(token.lexeme == "CLASS" || token.lexeme == "class" ) return ClassType;
        if(token.lexeme == "CONST" || token.lexeme == "const") return constType;
        if(token.lexeme == "VAR" || token.lexeme == "var") return identifierType;
    }
    if(token.lexeme == "Variable") return identifierType;
    if(token.lexeme == "{") return LBType;
    if(token.lexeme == "=") return AssType;
    if(token.lexeme == ",") return commaType;
    if(token.lexeme == ";") return semitype;  
    if(token.tokenType == "Numlit") return literalType;
    if(token.lexeme == "EOF") return EOFtype;
    return otherType;

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
    SymTable[StartState][ClassType] = ClassState;
    SymTable[ClassState][identifierType] = PrgmState;
    SymTable[PrgmState][LBType] = LBState;
    SymTable[LBState][constType] = constState;
    SymTable[constState][identifierType] = VState;
    SymTable[VState][AssType] = AssState;
    SymTable[AssState][int_Type] = literalState;
    SymTable[literalState][semitype] = LBState;
    SymTable[literalState][commaType] = LBState;
    SymTable[LBState][identifierType] = VarState;
    SymTable[VarState][identifierType] = VariState;
    SymTable[VariState][commaType] = VarState;
    SymTable[VariState][semitype] = LBState;
    SymTable[LBState][identifierType] = keyState;
    SymTable[LBState][keyType] = keyState;
    SymTable[keyState][constType] = constState;
    SymTable[keyState][identifierType] = VarState;
    SymTable[keyState][otherType] = keyState;
    SymTable[keyState][literalType] = integer_State;
    SymTable[keyState][EOFtype] = EOFState;
    SymTable[integer_State][otherType] = keyState;
    SymTable[integer_State][EOFtype] = EOFState;
    }

symbolstates symbolTable::getNextState(symbolstates currentState, symbolTypes input)
{
    int SymNext = SymTable[currentState][input];
    return static_cast<symbolstates>(SymNext);
}

void symbolTable::symbolize(const Tokens& initialToken, const vector<Tokens>& tokens)
{
    symbolstates currentState = StartState;
    symbolstates nextState;
    int Code = 0;
    int address = 0;
    string segment;

    for(const auto& token : tokens)
    {
        symbolTypes input = symMap(token);
        nextState = getNextState(currentState, input);
        currentState = nextState;
         switch(nextState)
        {
            case StartState:
                currentState = nextState;
                break;
            case ClassState:
                currentState = nextState;
                break;
            case PrgmState:
                addSymbol(token.lexeme, "PrgmName", "PrgmName", " ", "CS");
                break;
            case constState:
                addSymbol(token.lexeme, "const", " ", " ", "DS");
                address += 2;
                break;
            case:: VState:
            {
                currentState = nextState;
                addSymbol(token.lexeme, "constVar", " ", " ", "DS");
                int address =+ 2;
                string segment;
                break;
            }
            case:: AssState:
            {
                currentState = nextState;
                break;
            }
            case:: integer_State:
            {
                currentState = nextState;
                addSymbol(token.lexeme, "int", " ", " ", "DS");
                int address =+ 2;
                string segment;
                break;
            }
            case:: VarState:
            {
                currentState = nextState;
                string segment;
                break;
            }
            case:: VariState:
            {
                currentState = nextState;
                addSymbol(token.lexeme, "var", " ", " ", "DS");
                int address =+ 2;
                string segment;
                break;
            }
            case:: keyState:
            {
                currentState = nextState;
                break;
            }
            case:: literalState:
            {
                currentState = nextState;
                addSymbol(token.lexeme, "literal", " ", " ", "DS");
                int address =+ 2;
                string segment;
                break;
            }
            case:: EOFState:
            {
                currentState = nextState;
                break;
            }
        }
        
        
    }
        
}







