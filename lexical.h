#ifndef LEXICAL_H
#define LEXICAL_H
#include <string>
#include <iostream>
#include <string>
#include "States.h"
using namespace std;
const int NumberOfStates = static_cast<int>(StateCount); // Number of states
const int NumberOfInputs = static_cast<int>(typeCount); // Number of inputs
struct Tokens // Structure for tokens
{
    string lexeme; // Lexeme
    string tokenType; // Token type 
    Tokens(const string& lexeme, const string& tokenType); // Constructor
    Tokens() : lexeme(""), tokenType("") {} // Default constructor
};
class Lexical // Lexical class
{
private:
    string input; // Input
    Tokens tokens[1000]; // Array of tokens 
    size_t position; // Position
    size_t tokenCount; // Token count
    int StateTransitionTable[NumberOfStates][NumberOfInputs] = {}; // State transition table
    void LexicalFSA(); // FSA configuration
    void AddToTokenList(const string& lexeme, const string& tokenType); // Add to token list
    types getChType(char ch); // Get character type

public:
    explicit Lexical(); // Constructor
    void setInput(const string& lexeme); // Set input
    void tokenize(const string& lexeme); // Tokenize
    size_t getTokenCount() const; // Get token count
    string MapToken(const state, const string& lexeme) const; // Map token
    Tokens* getTokens(); // Get tokens
    state ReadRowsAndCollums(state currentState, types input); //Read the rows and collums of the table
};
#endif
