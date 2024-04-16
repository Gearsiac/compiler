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
struct ParseQuads // Structure for the parse quads
{
    string quad; // Quad
    ParseQuads(); // Constructor

};
class Parse // Parse class
{

    private: 
    size_t ParseStackCount; // Parse stack count
    size_t ParseQuadsCount; // Parse quads count
    char PDAPrecedence[OPState][OPInput] = {}; // PDA
    ParseQuads* ParseQuad[1000]; // Array of parse quads
    void ParseQuads(); // Quads
    void ParseLookAtStack( ); // Look at stack
    void PDAConfig(); // PDA configuration
    
    public:
        Parse(); // Constructor
        void ParseStack(); // Parse stack
        void ParsePush(); // Push
        void ParsePop(); // Pop
        void ParseAccept(); // Accept
        void ParseError(); // Error
        void ParseGoto(); // Goto
        void ParseTransition(); // Transition
        void ParseReduce(); // Reduce
        ParseOps ParseMap(const Tokens& token); // Parse map
        
};
#endif
