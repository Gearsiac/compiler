#ifndef LEXICAL_H
#define LEXICAL_H
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <iterator>
#include <regex>
#include <iomanip>
#include <fstream>
#include <sstream>
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
    void add(const string& lexeme, const string& types);
    types getChType(char ch);

public:
    explicit Lexical(FSA& fsa);
    void setInput(const string& lexeme);
    void tokenize(const string& lexeme);
    string keyword(const string& lexeme);
    vector<Tokens>& getTokens();
};
#endif