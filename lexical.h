#ifndef LEXICAL_H
#define LEXICAL_H
#include <string>
#include <iostream>
#include <string>
#include "States.h"

using namespace std;
const int NumberOfStates = static_cast<int>(StateCount);
const int NumberOfInputs = static_cast<int>(typeCount);
class FSA
{
private:

    int StateTransitionTable[NumberOfStates][NumberOfInputs] = {};
    void FSAConfig();
    
public:
    FSA();
    state MoveToNextStateOfTable(state currentState, types input);
};
struct Tokens
{
    string lexeme;
    string tokenType;
    Tokens(const string& lexeme, const string& tokenType);
    Tokens() : lexeme(""), tokenType("") {}
};
class Lexical
{
private:
    string input;
    FSA& fsa;
    Tokens tokens[10000]; 
    size_t position;
    size_t tokenCount;
    size_t tokenCapacity;
    void AddToTokenList(const string& lexeme, const string& tokenType);
    types getChType(char ch);

public:
    explicit Lexical(FSA& fsa);
    void setInput(const string& lexeme);
    void tokenize(const string& lexeme);
    void Resizing();
    size_t getTokenCount() const;
    string MapToken(const state, const string& lexeme) const;
    Tokens* getTokens(); 
};

#endif
