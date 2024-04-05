#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
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

vector<Tokens>& Lexical::getTokens()
{
    return tokens;
}
string Lexical :: map(state states, const string& lexeme) const
{   
    switch(states)
    {
        case state :: operation:
        if (lexeme == "+") return "Addition";
        if (lexeme == "-") return "Subtraction";
        if (lexeme == "*") return "Astrix";
        break;
        case state :: integerFinal:
        return "Integer";
        break;
        case state :: VariableFinal:
        return "Variable";
        break;
        case state :: DivisorFinal:
        return "Divisor";
        break;
        case state :: assignmentFinal:
        return "Assignment";
        break;
        case state :: equalityFinal:
        return "Equality";
        break;
        case state :: lessThanFinal:
        return "Less Than";
        break;
        case state :: lessThanEqualsStateFinal:
        return "Less Than Equals";
        break;
        case state :: greaterThanFinal:
        return "Greater Than";
        break;
        case state :: greaterThanEqualsStateFinal:
        return "Greater Than Equals";
        break;
        case state :: NotstateFinal:
        return "Not";
        break;
        case state :: notEqualsStateFinal:
        return "Not Equals";
        break;
        case state :: delimiterState:
        if(lexeme == ",") return "Comma";
        if(lexeme == ";") return "Semicolon";
        break;
        case state :: braceState:
        if(lexeme == "{") return "Left Brace";
        if(lexeme == "}") return "Right Brace";
        break;
        case state :: parenState:
        if(lexeme == "(") return "Left Parenthesis";
        if(lexeme == ")") return "Right Parenthesis";
        default:
        return "Error";
        break;
    }
    return "Error";
}
void Lexical::tokenize()
{
    state currentState = state::start;
    string currentlexeme;
    while(position < input.length())
    {
        char ch = input[position];
        types chType = getChType(ch);
        currentState = fsa.nextState(currentState, chType);
        switch (currentState)
        {
        case error:
            currentlexeme += ch;
            add(currentlexeme, "Error");
            currentlexeme.clear();
            currentState = start;
            break;
        case start:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case operation:
            currentlexeme += ch;
            add(currentlexeme, "Operation");
            currentlexeme.clear();
            currentState = start;
            break;
        case digitState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case integerFinal:
            currentlexeme += ch;
            add(currentlexeme, "Integer");
            currentlexeme.clear();
            currentState = start;
            break;
        case VariableState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case VariableFinal:
            currentlexeme += ch;
            add(currentlexeme, "Variable");
            tokens.clear();
            currentState = start;
            break;
        case slashState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case DivisorFinal:
            currentlexeme += ch;
            add(currentlexeme, "Divisor");
            currentlexeme.clear();
            currentState = start;
            break;
        case commentState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case commentFinal:
            currentlexeme += ch;
            currentlexeme.clear();
            currentState = start;
            break;
        case equalsState:   
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case assignmentFinal:   
            currentlexeme += ch;
            add(currentlexeme, "Assignment");
            currentlexeme.clear();
            currentState = start;
            break;
        case equalityFinal:
            currentlexeme += ch;
            add(currentlexeme, "Equality");
            currentlexeme.clear();
            currentState = start;
            break;
        case lessThanState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case lessThanFinal:
            currentlexeme += ch;
            add(currentlexeme, "Less Than");
            currentlexeme.clear();
            currentState = start;
            break;
        case lessThanEqualsStateFinal:  
            currentlexeme += ch;
            add(currentlexeme, "Less Than Equals");
            currentlexeme.clear();
            currentState = start;
            break;
        case greaterThanState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case greaterThanFinal:
            currentlexeme += ch;
            add(currentlexeme, "Greater Than");
            currentlexeme.clear();
            currentState = start;
            break;
        case greaterThanEqualsStateFinal:
            currentlexeme += ch;
            add(currentlexeme, "Greater Than Equals");
            currentlexeme.clear();
            currentState = start;
            break;
        case exclemationState:
            currentlexeme += ch;
            currentState = fsa.nextState(currentState, chType);
            position++;
            break;
        case NotstateFinal:
            currentlexeme += ch;
            add(currentlexeme, "Not");
            currentlexeme.clear();
            currentState = start;
            break;
        case notEqualsStateFinal:
            currentlexeme+= ch;
            add(currentlexeme, "Not Equals");
            currentlexeme.clear();
            currentState = start;
            break;
        case delimiterState:
            currentlexeme += ch;
            add(currentlexeme, "Delimiter");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case braceState:
            currentlexeme += ch;
            add(currentlexeme, "Brace");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case parenState:
            currentlexeme += ch;
            add(currentlexeme, "Parenthesis");
            tokens.clear();
            currentState = start;
            position++;
            break;
        default:
            break;
        }
    }   
}


