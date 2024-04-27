#ifndef PARSE_H
#define PARSE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "lexical.h"
#include "symbol.h"
#include "EnumerationTypes.h"
using namespace std;
const int OPState  = static_cast<int>(ParseCount); // Number of states
const int OPInput = static_cast<int>(ParseCount); // Number of inputs
const int maxStack = 1000; // Maximum number of stack

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
    int StackCount = 0; // Parse stack count
    int QuadsCount = 0; // Parse quads count
    int LabelCount = 1; // IF then, Else Label count
    int WhileCount = 0;
    int WhileLabelCount = 1; // While count for While Label Stack
    int FixerCount = 1; // Fixer count
    int JMPCount = 1; // JMP count
    int EndOfStackCount = 1; // End of stack count
    int TempCount = 1; // Temp count
    char PDAPrecedenceTable[OPState][OPInput] = {}; // PDA
    Quads ParseQuads[maxStack]; // Array of parse quad
    Tokens* ParseStack[maxStack]; // Array of parse stack
    string FixerUpper[maxStack]; // Fixer upper
    string WhileStack[maxStack]; // Label stack
    string EndOfStack[maxStack]; // End of stack
    string JumpStack[maxStack]; // Jump stack
    void PDAConfig(); // PDA configuration
    
    public:
        Parse(); // Constructor
        ParseOps ParseMap(const Tokens& token); // Parse map
        char ReadRowsAndCollums(ParseOps currentState, ParseOps input); // Read the rows and collums
        int getQuadsCount() const; // Get parse quads count
        Quads* getParseQuads(); // Get parse quads
        void AddToQuads(const string& op, const string& arg1, const string& arg2, const string& Temp); // Add to parse quads
        void Parseing(const Tokens& token, Tokens* tokens, int tokenCount); // Parse
        ParseOps PopAndLockTheTopOPThatDrop(); // get top operator 
        void LabelGenerator(string Label); // Label generator
        void WhileGenerator(string While); // While generator
        void AddTofixer(string Label); // Add to fixer
        void AddToWhileStack(string While); // Add to while stack
        void AddToEndOfStack(string Label); // Add to end of stack
        void AddToJumpStack(string Jump); // Add to jump stack
        void HandleClosingPrens(); // done
        void HandleClosingBraces(); // done
        void HandleIF(); // nedd
        void HandleThen(); // Need
        void HandleElse(); // Handle if else
        void HandelEOF(); // Handle if then
        void PopIFTHEN(); // Pop if then
        void PopIfThenElse(); // Pop if then else
        void HandleWhile(); // Handle while
        void HandleDo(); // Handle do
        void HandleAritmatic(); // Handle aritmatic
        void PopWhileDo(); // Pop while do
        Quads* PrintQuads(); // Print the quads
};
#endif