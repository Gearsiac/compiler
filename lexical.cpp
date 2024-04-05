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
            add(lexeme, "Error");
            tokens.clear();
            currentState = start;
            break;
        case start:
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case operation:
            lexeme += ch;
            add(lexeme, "Operation");
            tokens.clear();
            currentState = start;
            break;
        case digitState:
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case integerFinal:
            lexeme += ch;
            add(lexeme, "Integer");
            tokens.clear();
            currentState = start;
            break;
        case VariableState:
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case VariableFinal:
            lexeme += ch;
            add(lexeme, "Variable");
            tokens.clear();
            currentState = start;
            break;
        case slashState:
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case DivisorFinal:
            lexeme += ch;
            add(lexeme, "Divisor");
            tokens.clear();
            currentState = start;
            break;
        case commentState:
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case commentFinal:
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case equalsState:   
            lexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case assignmentFinal:   
            lexeme += ch;
            add(lexeme, "Assignment");
            tokens.clear();
            currentState = start;
            break;
        case equalityFinal:
            lexeme += ch;
            add(lexeme, "Equality");
            tokens.clear();
            currentState = start;
            break;
        case lessThanState:
            lexeme += ch;
            position++;
            currentState = fsa.nextState(currentState, chType);
            break;
        case lessThanFinal:
            lexeme += ch;
            add(lexeme, "Less Than");
            tokens.clear();
            currentState = start;
            break;
        case lessThanEqualsStateFinal:  
            lexeme += ch;
            add(lexeme, "Less Than Equals");
            tokens.clear();
            currentState = start;
            break;
        case greaterThanState:
            lexeme += ch;
            position++;
            currentState = fsa.nextState(currentState, chType);
            break;
        case greaterThanFinal:
            lexeme += ch;
            add(lexeme, "Greater Than");
            tokens.clear();
            currentState = start;
            break;
        case greaterThanEqualsStateFinal:
            lexeme += ch;
            add(lexeme, "Greater Than Equals");
            tokens.clear();
            currentState = start;
            break;
        case exclemationState:
            lexeme += ch;
            position++;
            currentState = fsa.nextState(currentState, chType);
            break;
        case NotstateFinal:
            lexeme += ch;
            add(lexeme, "Not");
            tokens.clear();
            currentState = start;
            break;
        case notEqualsStateFinal:
            lexeme += ch;
            add(lexeme, "Not Equals");
            tokens.clear();
            currentState = start;
            break;
        case delimiterState:
            lexeme += ch;
            position++;
            add(lexeme, "Delimiter");
            tokens.clear();
            currentState = start;
            break;
        case braceState:
            lexeme += ch;
            position++;
            add(lexeme, "Brace");
            tokens.clear();
            currentState = start;
            break;
        case parenState:
            lexeme += ch;
            position++;
            add(lexeme, "Parenthesis");
            tokens.clear();
            currentState = start;
            break;
        default:
            break;
        }
    }   
}


