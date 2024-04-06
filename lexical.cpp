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
#include "lexical.h"
#include "States.h"
using namespace std;

Tokens::Tokens(const string& lexeme, const string& tokenType) : lexeme(lexeme), tokenType(tokenType)
{
    

}
Lexical::Lexical(FSA& fsa) : fsa(fsa)
{

}
void Lexical::add(const string& lexeme, const string& tokenType)
{
    tokens.push_back(Tokens(lexeme, tokenType));
}
void Lexical::setInput(const string& ins)
{
    input = ins;
    position = 0;
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

vector<Tokens>& Lexical::getTokens()
{
    return tokens;
}
string Lexical::map(state states, const string& lexeme) const
{
    switch(states)
    {
        case state :: operation:
            if (lexeme == "+") return "Addition";
            if (lexeme == "-") return "Subtraction";
            if (lexeme == "*") return "Multiplication";
            break;
        case state::integerFinal:
            return "Integer";
        case state::VariableFinal:
            return "Variable";
        case state::DivisorFinal:
            return "Divisor";
        case state::assignmentFinal:
            return "Assignment";
        case state::equalityFinal:
            return "Equality";
        case state:: lessThanFinal:
            return "Less Than";
        case state :: lessThanEqualsStateFinal:
            return "Less Than Equals";
        case state ::greaterThanFinal:
            return "Greater Than";
        case state :: greaterThanEqualsStateFinal:
            return "Greater Than Equals";
        case state :: NotstateFinal:
            return "Not";
        case state ::notEqualsStateFinal:
            return "Not Equals";
        case state :: delimiterState:
            if (lexeme == ",") return "Comma";
            if (lexeme == ";") return "Semicolon";
            break;
        case state :: braceState:
            if (lexeme == "{") return "Left Brace";
            if (lexeme == "}") return "Right Brace";
            break;
        case state :: parenState:
            if (lexeme == "(") return "Left Parenthesis";
            if (lexeme == ")") return "Right Parenthesis";
            break;
        default:
            break;
    }
    return "Error"; // This ensures a default return if no case matches
}
void Lexical::tokenize(const string& ins)
{
    state currentState = start;
    state nextState;
    string currentlexeme;
    while(position < input.length())
    {
        char ch = input[position];
        types chType = getChType(ch);
        nextState = fsa.nextState(currentState, chType);
        switch (nextState)
        {
        case state::start:
            currentState = fsa.nextState(currentState, chType);
            break;
        case state ::error:
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: operation:
            currentlexeme += ch;
            add(currentlexeme, "Operation");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: digitState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: integerFinal:
            add(currentlexeme, "Integer");
            currentlexeme.clear();
            currentState = start;
            break;
        case state ::VariableState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: VariableFinal:
            add(currentlexeme, "Variable");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: slashState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case state::DivisorFinal:
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: commentState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case state :: commentFinal:
            currentlexeme += ch;
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: equalsState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: assignmentFinal:   
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: equalityFinal:
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: lessThanState:
            currentlexeme+= ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case state :: lessThanFinal:
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: lessThanEqualsStateFinal: 
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: greaterThanState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case state :: greaterThanFinal:
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: greaterThanEqualsStateFinal:
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: exclemationState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case state :: NotstateFinal:
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: notEqualsStateFinal:
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: delimiterState:
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: braceState:
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: parenState:
            currentlexeme += ch;
            add(currentlexeme, map(currentState, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        default:
            break;
        }
    }   
}


