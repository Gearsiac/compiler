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
    while(position < input.length())
    {
        state currentState = start;
        string lexeme;
        char ch = input[position];
        types chType = getChType(ch);
        currentState = fsa.nextState(currentState, chType);
        switch (currentState)
        {
        case error:
            lexeme += ch;
            position++;
            add(lexeme, "Error");
            tokens.clear();
            break;
        case start:
            position++;
            break;
        case operation:
            lexeme += ch;
            position++;
            add(lexeme, "Operation");
            tokens.clear();
            break;
        case digitState:
            lexeme += ch;
            position++;
            break;
        case integerFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Integer");
            tokens.clear();
            break;
        case VariableState:
            lexeme += ch;
            position++;
            break;
        case VariableFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Variable");
            tokens.clear();
            break;
        case slashState:
            lexeme += ch;
            position++;
            break;
        case DivisorFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Divisor");
            tokens.clear();
            break;
        case commentState:
            lexeme += ch;
            position++;
            break;
        case commentFinal:
            lexeme += ch;
            position++;
            break;
        case equalsState:   
            lexeme += ch;
            position++;
            break;
        case assignmentFinal:   
            lexeme += ch;
            position++;
            add(lexeme, "Assignment");
            tokens.clear();
            break;
        case equalityFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Equality");
            tokens.clear();
            break;
        case lessThanState:
            lexeme += ch;
            position++;
            break;
        case lessThanFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Less Than");
            tokens.clear();
            break;
        case lessThanEqualsStateFinal:  
            lexeme += ch;
            position++;
            add(lexeme, "Less Than Equals");
            tokens.clear();
            break;
        case greaterThanState:
            lexeme += ch;
            position++;
            break;
        case greaterThanFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Greater Than");
            tokens.clear();
            break;
        case greaterThanEqualsStateFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Greater Than Equals");
            tokens.clear();
            break;
        case exclemationState:
            lexeme += ch;
            position++;
            break;
        case NotstateFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Not");
            tokens.clear();
            break;
        case notEqualsStateFinal:
            lexeme += ch;
            position++;
            add(lexeme, "Not Equals");
            tokens.clear();
            break;
        case delimiterState:
            lexeme += ch;
            position++;
            add(lexeme, "Delimiter");
            tokens.clear();
            break;
        case braceState:
            lexeme += ch;
            position++;
            add(lexeme, "Brace");
            tokens.clear();
            break;
        case parenState:
            lexeme += ch;
            position++;
            add(lexeme, "Parenthesis");
            tokens.clear();
            break;
        default:
            break;
        }
    }   
}


