#include <string>
#include <iostream>
#include <iomanip>
#include "lexical.h"
#include "EnumerationTypes.h"
#include "Files.h"
#include "symbol.h"
using namespace std;
void symbolTable::SymbolTableFSA() //function to configure the symbolStates
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

    SymTable[literalState][constIdentifierType] = keyState;
    SymTable[literalState][VarIdentifierType] = keyState;
    SymTable[literalState][keyType] = keyState;
    SymTable[literalState][semitype] = keyState;
    SymTable[literalState][AssType] = keyState;
    SymTable[literalState][commaType] = keyState;
    SymTable[literalState][LBType] = keyState;
    SymTable[literalState][variableType] = keyState;
    SymTable[literalState][int_Type] = keyState;
    SymTable[literalState][otherType] = keyState;
    SymTable[literalState][EOFtype] = EOFState;
} 
symbolTable::symbolTable() //constructor
{
    SymbolTableFSA(); //configure the symbol states
}
symbolstates symbolTable::ReadRowsAndCollums(symbolstates currentState, symbolTypes input) //function to read the rows and collums
{
    int SymTableNextStateTransition = SymTable[currentState][input]; // Get the next state
    return static_cast<symbolstates>(SymTableNextStateTransition); // Return the next state
}

symbol :: symbol(const string& syms, const string& Classification, const string& value, const int address, const string& segment) : 
syms(syms), Classification(Classification), value(value), address(address), segment(segment){} //constructor

void symbolTable::addToSymbolTable(const string& syms, const string& Classification, const string& value, const int address, const string& segment) //function to add to the symbol table  
{
    symbols[SymbolCount++] = symbol(syms, Classification, value, address, segment); // Add to the symbol table
}
symbolTypes symbolTable::symMap(const Tokens &token) //function to map the symbols
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
        if(token.lexeme == "CIN" || token.lexeme == "cin") return keyType;
        if(token.lexeme == "COUT" || token.lexeme == "cout") return keyType;
    }
    if(token.lexeme == "{") return LBType;
    if(token.lexeme == "=") return AssType;
    if(token.lexeme == ",") return commaType;
    if(token.lexeme == ";") return semitype;  
    if(token.tokenType == "Numlit") return int_Type;
    if(token.tokenType == "EOF") return EOFtype;
    return otherType;
}         
symbol* symbolTable :: getSymbols() //function to get the symbols
{
    return symbols;
}
int symbolTable::getSymbolCount() const //function to get the symbol count
{
    return SymbolCount;
}
void symbolTable::symTable(const Tokens& initialToken, Tokens* tokens, size_t tokenCount) //function to create the symbol table 
{
    symbolstates currentState = StartState; // Set the current state
    symbolstates NextStateTrasition; // Set the next state
    int Code = 0; //for adding the code addess
    int address = 0; //for adding the data address
    string sym, Classification, value, segment; // Set the symbol, classification, value, and segment
    for(int i = 0; i < tokenCount; i++) // Loop through the tokens
    {
        Tokens token = tokens[i]; // Get the token
        string tokenType = token.tokenType; // Get the token type
        string lexeme = token.lexeme; // Get the lexeme
        symbolTypes input = symMap(token); // Get the input
        NextStateTrasition = ReadRowsAndCollums(currentState, input); // Get the next state
        currentState = NextStateTrasition; // Set the current state
        switch(NextStateTrasition) // Switch statement for the next state
        {
            case StartState:
                currentState = NextStateTrasition;
                break;
            case ClassState:
                currentState = NextStateTrasition;
                break;
            case PrgmState:
                addToSymbolTable(lexeme, "PrgmName", " ", Code, "CS");
                Code += 2;
                currentState = NextStateTrasition;
                break;
            case LBState:
                currentState = NextStateTrasition;
                break;
            case constState:
                currentState = NextStateTrasition;
                break;
            case VState:
                sym = lexeme;
                Classification = "CONST";
                currentState = NextStateTrasition;
                break;
            case AssState:
                currentState = NextStateTrasition;
                break;
            case integer_State:
                value = token.lexeme;
                addToSymbolTable(sym, Classification, value, address, "DS");
                address += 2;
                currentState = NextStateTrasition;
                break;
            case VarState:
                currentState = NextStateTrasition;
                break;
            case VariState:
                sym = lexeme;
                Classification = "VAR";
                value = "?";
                addToSymbolTable(sym, Classification, value, address, "DS");
                address += 2;
                currentState = NextStateTrasition;
                break;
            case keyState:
                currentState = NextStateTrasition;
                break;
            case literalState:
                sym = lexeme;
                Classification = "Numeric Literal";
                value = token.lexeme;
                addToSymbolTable(sym, Classification, value, address, "DS");
                address += 2;
                currentState = NextStateTrasition;
                break;
            case EOFState:
                break;
            default:
                cout << "Error" << endl;
                break;
        }
    }
    addToSymbolTable("Temp1", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp2", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp3", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp4", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp5", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp6", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp7", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp8", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp9", "Var (int)", " ", address, "DS");
    address += 2;
    addToSymbolTable("Temp10", "Var (int)", " ", address, "DS");
    address += 2;

}

