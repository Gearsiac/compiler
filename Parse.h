#ifndef PARSE_H
#define PARSE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include "lexical.h"
#include "symbol.h"
#include "States.h"
using namespace std;
const int OPState  = static_cast<int>(ParseCount); // Number of states
const int OPInput = static_cast<int>(ParseCount); // Number of inputs
const int maxQuads = 1000; // Maximum number of quads
const int maxFixer = 1000; // Maximum number of fixer
const int maxStack = 1000; // Maximum number of stack
const int maxWhile = 1000; // Maximum number of while

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
    int StackCount; // Parse stack count
    int QuadsCount; // Parse quads count
    int LabelCount; // Label count
    int WhileCount; // While count
    int FixerCount; // Fixer count
    int TempCount; // Temp count
    char PDAPrecedenceTable[OPState][OPInput] = {}; // PDA
    Quads* ParseQuads[maxQuads]; // Array of parse quad
    Tokens* ParseStack[maxStack]; // Array of parse stack
    int FixerUpper[maxFixer]; // Fixer upper
    int WhileStack[maxStack]; // Label stack
    void PDAConfig(); // PDA configuration
    
    public:
        Parse(); // Constructor
        ParseOps ParseMap(const Tokens& token); // Parse map
        char ReadRowsAndCollums(ParseOps currentState, ParseOps input); // Read the rows and collums
        int getQuadsCount() const; // Get parse quads count
        Quads* getParseQuads(); // Get parse quads
        void AddToQuads(const string& op, const string& arg1, const string& arg2, const string& Temp); // Add to parse quads
        void AddToFixerUpper(const string fixer); // Add to fixer upper
        void AddToWhileStack(const string While); // Add to while stack
        void Parseing(const Tokens& token, Tokens* tokens, int tokenCount); // Parse
        ParseOps PopAndLockTheTopOPThatDrop(); // Pop and lock the top OP that drop
        void LabelGenerator(string Label); // Label generator
        void WhileGenerator(string While); // While generator
        void HandleClosingPrens(const Tokens& token); // Handle closing prens
        void HandleClosingBraces();
        void HandleIF(); // Handle if
        void HandleThen(); // Handle then
        void HandleIfElse(); // Handle if else
        void PopIFTHEN(); // Pop if then
        void PopIfThenElse(); // Pop if then else
        void HandleWhile(); // Handle while
        void HandleDo(); // Handle do
        void PopWhileDo(); // Pop while do
        void PrintStack(); // Print stack
        
        
         
        
};
#endif