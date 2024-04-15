#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include "lexical.h"
#include "symbol.h"
#include "States.h"
using namespace std;
struct ParseStack // Structure for the parse stack
{
    string stack; // Stack
    string input; // Input
    string action; // Action
    ParseStack(const string& stack, const string& input, const string& action); // Constructor
    ParseStack() : stack(""), input(""), action(""){} // Default constructor
};
struct ParseQuads // Structure for the parse quads
{
    string quad; // Quad
    string action; // Action
    ParseQuads(const string& quad, const string& action); // Constructor
    ParseQuads() : quad(""), action(""){} // Default constructor
};
class Parse // Parse class
{

    private:
         

    public:
        Parse(); // Constructor
        void ParseStack();
        void ParsePush(); // Push
        void ParsePop(); // Pop
        void ParseAccept(); // Accept
        void ParseError(); // Error
        void ParseQuads(); // Quads
        void ParseGoto(); // Goto
        void ParseLookAtStack(); // Look at stack

};
#endif
