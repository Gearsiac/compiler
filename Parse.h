#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <iostream>
#include <iomanip>
#include <stack>
#include "lexical.h"
#include "symbol.h"
#include "States.h"
using namespace std;
const int OPState  = static_cast<int>(ParseCount); // Number of states
const int OPInput = static_cast<int>(ParseCount); // Number of inputs
const int maxQuads = 1000; // Maximum number of quads
const int maxStack = 1000; // Maximum number of stack
const int maxFixer = 1000; // Maximum number of fixer
struct Quads // Structure for the parse quads
{

    string op; // Operator
    string arg1; // Argument 1
    string arg2; // Argument 2
    string Temp; // Temp
    Quads(const string& op, const string& arg1, const string& arg2, const string& Temp); // Constructor
    Quads() : op("?"), arg1("?"), arg2("?"), Temp("?") {} // Default constructor

};
class Parse // Parse class
{

    private: 
    size_t StackCount; // Parse stack count
    size_t QuadsCount; // Parse quads count
    char PDAPrecedenceTable[OPState][OPInput] = {}; // PDA
    Quads* ParseQuads[maxQuads]; // Array of parse quad
    Tokens* ParseStack[maxStack]; // Array of parse stack
    int FixerUpper[maxFixer]; // Fixer upper
    void PDAConfig(); // PDA configuration
    
    public:
        Parse(); // Constructor
        ParseOps ParseMap(const Tokens& token); // Parse map
        char ReadRowsAndCollums(ParseOps currentState, ParseOps input); // Read rows and collums
        size_t getQuadsCount() const; // Get parse quads count
        size_t getStackCount() const; // Get parse stack count
        Quads* getParseQuads(); // Get parse quads
        void AddToQuads(const string& op, const string& arg1, const string& arg2, const string& Temp); // Add to parse quads
        void Parseing(const Tokens& token, Tokens* tokens, int tokenCount); // Parse
        void PopAndLockTheTopOPThatDrop(); // Pop and lock the top ops that drop
        
        
         
        
};
#endif
