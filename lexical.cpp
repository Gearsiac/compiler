#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include "FSA.h"
#include "lexical.h"
#include "States.h"
#include "FSA.h"
using namespace std;

void Lexical::add(const string& lexeme, const string& tokenType)
{
    tokens.push_back(Tokens(lexeme, tokenType));
}
void Lexical::setInput(const string& ins)
{
    input = ins;
}
types Lexical::getChType(char ch)
{
    if (isalpha(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return letter;
    }
    else if (isdigit(ch >= '0' && ch <= '9'))
    {
        return digit;
    }
    else if (ch == '*')
    {
        return astrix;
    }
    else if (ch == '+')
    {
        return plusType;
    }
    else if (ch == '-')
    {
        return minusType;
    }
    else if (ch == '/')
    {
        return divisor;
    }
    else if (ch == '=')
    {
        return equals;
    }
    else if (ch == '<')
    {
        return lessThan;
    }
    else if (ch == '>')
    {
        return greaterThan;
    }
    else if (ch == '!')
    {
        return exlimation;
    }
    else if (ch == '(' )
    {
        return leftparen;
    }
    else if (ch == ')')
    {
        return rightparen;
    }
    else if (ch == '{')
    {
        return leftbrace;
    }
    else if (ch == '}')
    {
        return rightbrace;
    }
    else if (ch == ',')
    {
        return comma;
    }
    else if (ch == ';')
    {
        return semicolon;
    }
    else if (isspace(ch))
    {
        return WS;
    }
    else
    {
        return other;
    }
}
void Lexical::tokenize()
{   
    
    
}


