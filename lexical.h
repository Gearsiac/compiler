#ifndef LEXICAL_H
#define LEXICAL_H
#include <iostream>
#include <string>
#include <vector>
#include "FSA.h"
#include "States.h"

using namespace std;

struct Tokens
{
    string lexeme;
    string tokenType;
    Tokens(const string& lexeme, const string& tokenType);
};
class Lexical
{
private:
    string input;
    FSA fsa;
    vector<Tokens> tokens;
    size_t position = 0;
    void add(const string& lexeme, const string& tokenType);
    types getChType(char ch);

public:
    Lexical(FSA& fsa);
    void setInput(const string& ins);
    void tokenize();
    vector<Tokens>& getTokens();
};

#endif