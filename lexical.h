#define LEXICAL_H
#ifndef LEXICAL_H
#include <iostream>
#include <string>
#include <vector>
#include "tokens.h"
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
    FSA* fsa;
    void Tokens(const string& lexeme, const string& tokenType);
    vector<Tokens> tokens;
    size_t positon = 0;
    void add(const string& lexeme, const string& input);
    types getCharType(char ch);

    public:
    Lexical(const string& FSA fsa);
    void analyze();
    vector<Tokens> getTokens();
    

    

};





#endif
