#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include "FSA.h"
#include "lexical.h"
#include "States.h"
using namespace std;



void Lexical::add(const string& lexeme, const string& tokenType)
{
    tokens.push_back(Tokens(lexeme, tokenType));
}
void Lexical::setInput(const string& ins)
{
    input = ins;
    size_t postion = 0;
    tokens.clear();
}
types Lexical::getChType(char ch)
{
    if (isalpha(ch))
    {
        return letter;
    }
    else if (isdigit(ch))
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
Lexical::Lexical(FSA& fsa)
{
    fsa = FSA(fsa);
}
vector<Tokens>& Lexical::getTokens()
{
    return tokens;
}
Tokens::Tokens(const string& lexeme, const string& tokenType)
{
    this->lexeme = lexeme;
    this -> tokenType = tokenType;
}
void Lexical::tokenize()
{
    state currentState = start;
    string lexeme = "";
    while (position < input.size())
    {
        char ch = input[position];
        types chType = getChType(ch);
        state nextState = fsa.nextState(currentState, chType);
        switch (currentState)
        {
        case start:
            if (lexeme.size() > 0)
            {
                add(lexeme, "error");
                lexeme = "";
            }
            break;
        case error:
            if (lexeme.size() > 0)
            {
                add(lexeme, "error");
                lexeme = "";
            }
            break;
        case digitState:
            lexeme += ch;
            break;
        case integerFinal:
            add(lexeme, "integer");
            lexeme = "";
            break;
        case VariableState:
            lexeme += ch;
            break;
        case VariableFinal:
            add(lexeme, "variable");
            lexeme = "";
            break;
        case slashState:
            lexeme += ch;
            break;
        case commentState:
            lexeme += ch;
            break;
        case commentFinal:
            add(lexeme, "comment");
            lexeme = "";
            break;
        case DivisorFinal:
            add(lexeme, "divisor");
            lexeme = "";
            break;
        case equalsState:
            lexeme += ch;
            break;
        case assignmentFinal:
            add(lexeme, "assignment");
            lexeme = "";
            break;
        case equalityFinal:
            add(lexeme, "equality");
            lexeme = "";
            break;
        case lessThanState:
            lexeme += ch;
            break;
        case lessThanFinal:
            add(lexeme, "less than");
            lexeme = "";
            break;
        case lessThanEqualsStateFinal:
            add(lexeme, "less than equals");
            lexeme = "";
            break;
        case greaterThanState:
            lexeme += ch;
            break;
        case greaterThanFinal:
            add(lexeme, "greater than");
            lexeme = "";
            break;
        case greaterThanEqualsStateFinal:
            add(lexeme, "greater than equals");
            lexeme = "";
            break;
        case exclemationState:
            lexeme += ch;
            break;
        case NotstateFinal:
            add(lexeme, "not");
            lexeme = "";
            break;
        case notEqualsStateFinal:
            add(lexeme, "not equals");
            lexeme = "";
            break;
        case delimiterState:
            add(lexeme, "delimiter");
            lexeme = "";
            break;
        case braceState:
            add(lexeme, "brace");
            lexeme = "";
            break;
        case parenState:
            add(lexeme, "paren");
            lexeme = "";
            break;
        default:
            break;
        }
        position++;
    }


}


