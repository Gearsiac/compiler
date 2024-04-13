#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include "lexical.h"
#include "States.h"
#include "Files.h"
#include "symbol.h"

using namespace std;
symbol :: symbol(const string& syms, const string& Classification, const string& value, const int address, const string& segment) : 
syms(syms), Classification(Classification), value(value), address(address), segment(segment){}

void symbolTable::addToSymbolTable(const string& syms, const string& Classification, const string& value, const int address, const string& segment) //chanage 
{
    symbols[SymbolCount] = symbol(syms, Classification, value, address, segment);
    SymbolCount++;
}

symbolTypes symbolTable::symMap(const Tokens &token)
{
    if(token.tokenType == "Variable") return variableType;
    if(token.tokenType == "RESERVED WORD")
    {
        if(token.lexeme == "CLASS" || token.lexeme == "class" ) return ClassType;
        if(token.lexeme == "CONST" || token.lexeme == "const") return constIdentifierType;
        if(token.lexeme == "VAR" || token.lexeme == "var") return VarIdentifierType;
        if(token.lexeme == "WHILE" || token.lexeme == "while") return keyType;
        if(token.lexeme == "IF" || token.lexeme == "if") return keyType;
        if(token.lexeme == "ELSE" || token.lexeme == "else") return keyType;
        if(token.lexeme == "PROCEDURE" || token.lexeme == "procedure") return keyType;
        if(token.lexeme == "ODD" || token.lexeme == "odd") return keyType;
        if(token.lexeme == "CALL" || token.lexeme == "call") return keyType;
        if(token.lexeme == "THEN" || token.lexeme == "then") return keyType;
        if(token.lexeme == "DO" || token.lexeme == "do") return keyType;
        
    }
    if(token.lexeme == "{") return LBType;
    if(token.lexeme == "=") return AssType;
    if(token.lexeme == ",") return commaType;
    if(token.lexeme == ";") return semitype;  
    if(token.tokenType == "Numlit") return int_Type;
    if(token.tokenType == "EOF") return EOFtype;


    return otherType;
    


}         
symbol* symbolTable :: getSymbols()
{
    return symbols;
}

symbolTable::symbolTable()
{
    SymConfig();
}

size_t symbolTable::getSymbolCount() const
{
    return SymbolCount;
}

void symbolTable::SymConfig()
{
    SymTable[StartState][ClassType] = ClassState;
    SymTable[ClassState][variableType] = PrgmState;
    SymTable[PrgmState][LBType] = LBState;
    SymTable[LBState][constIdentifierType] = constState;
    SymTable[LBState][VarIdentifierType] = VarState;
    SymTable[LBState][variableType] = keyState;
    SymTable[LBState][keyType] = keyState;
    SymTable[constState][variableType] = VState;
    SymTable[VState][AssType] = AssState;
    SymTable[AssState][int_Type] = integer_State;
    SymTable[integer_State][semitype] = LBState;
    SymTable[integer_State][commaType] = constState;
    SymTable[VarState][variableType] = VariState;
    SymTable[VariState][commaType] = VarState;
    SymTable[VariState][semitype] = LBState;
    SymTable[keyState][constIdentifierType] = constState;
    SymTable[keyState][VarIdentifierType] = VarState;
    SymTable[keyState][AssType] = keyState;
    SymTable[keyState][semitype] = keyState;
    SymTable[keyState][commaType] = keyState;
    SymTable[keyState][LBType] = keyState;
    SymTable[keyState][keyType] = keyState;
    SymTable[keyState][variableType] = keyState;
    SymTable[keyState][int_Type] = literalState;
    SymTable[keyState][otherType] = keyState;
    SymTable[keyState][EOFtype] = EOFState;
    SymTable[literalState][semitype] = keyState;
    SymTable[literalState][commaType] = keyState;
    SymTable[literalState][LBType] = keyState;
    SymTable[literalState][variableType] = keyState;
    SymTable[literalState][int_Type] = keyState;
    SymTable[literalState][otherType] = keyType;
    SymTable[literalState][EOFtype] = EOFState;
    }

symbolstates symbolTable::getNextState(symbolstates currentState, symbolTypes input)
{
    int SymNext = SymTable[currentState][input];
    return static_cast<symbolstates>(SymNext);
}
void symbolTable::symTable(const Tokens& initialToken, Tokens* tokens, int numTokens) 
{
    symbolstates currentState = StartState;
    symbolstates nextState;
    int Code = 0;
    int address = 0;
    string sym, Classification, value, segment;

    for(int i = 0; i < numTokens; i++)
    {
        Tokens token = tokens[i];
        string tokenType = token.tokenType;
        string lexeme = token.lexeme;
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
                addToSymbolTable(lexeme, "PrgmName", " ", Code, "CS");
                Code += 2;
                currentState = nextState;
                break;
            case LBState:
                currentState = nextState;
                break;
            case constState:
                currentState = nextState;
                break;
            case VState:
                sym = lexeme;
                Classification = "CONST";
                currentState = nextState;
                break;
            case AssState:
                currentState = nextState;
                break;
            case integer_State:
                value = token.lexeme;
                addToSymbolTable(sym, Classification, value, address, "DS");
                address += 2;
                currentState = nextState;
                break;
            case VarState:
                currentState = nextState;
                break;
            case VariState:
                sym = lexeme;
                Classification = "VAR";
                value = "?";
                addToSymbolTable(sym, Classification, value, address, "DS");
                address += 2;
                currentState = nextState;
                break;
            case keyState:
                currentState = nextState;
                break;
            case literalState:
                sym = lexeme;
                Classification = "LITERAL";
                value = token.lexeme;
                addToSymbolTable(sym, Classification, value, address, "DS");
                address += 2;
                currentState = nextState;
                break;
            case EOFState:
                break;
            default:

                break;
        }
    }
    int temp;
    addToSymbolTable("Temp1", "Var", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp2", "Var", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp3", "Var", " ", address, "DS");
    address += 2;

}

