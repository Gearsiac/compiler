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
void Lexical::add(const string& lexeme, const string& types)
{
    tokens.push_back(Tokens(lexeme, types));
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
        return types:: letter;
    }
    else if (isdigit(ch))
    {
        return types :: digit;
    }
    else if (ch == '*')
    {
        return types::astrix;
    }
    else if (ch == '+')
    {
        return types::plusType;
    }
    else if (ch == '-')
    {
        return types:: minusType;
    }
    else if (ch == '/')
    {
        return types::divisor;
    }
    else if (ch == '=')
    {
        return types::equals;
    }
    else if (ch == '<')
    {
        return types::lessThan;
    }
    else if (ch == '>')
    {
        return types::greaterThan;
    }
    else if (ch == '!')
    {
        return types::exlimation;
    }
    else if (ch == '(' )
    {
        return types::leftparen;
    }
    else if (ch == ')')
    {
        return types::rightparen;
    }
    else if (ch == '{')
    {
        return types::leftbrace;
    }
    else if (ch == '}')
    {
        return types::rightbrace;
    }
    else if (ch == ',')
    {
        return types::comma;
    }
    else if (ch == ';')
    {
        return types::semicolon;
    }
    else if (isspace(ch))
    {
        return types::WS;
    }
    else
    {
        return types::other;
    }
}

vector<Tokens>& Lexical::getTokens()
{
    return tokens;
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
            currentState = nextState;
            position++;
            break;
        case state ::error:
            add(currentlexeme, "error");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state ::operation:
            currentlexeme += ch;
            if(ch == '*')
            {
                add(currentlexeme, "astrix");
                currentlexeme.clear();
                currentState = start;
            }
            else if(ch == '+')
            {
                add(currentlexeme, "plus");
                currentlexeme.clear();
                currentState = start;
            }
            else if(ch == '-')
            {
                add(currentlexeme, "minus");
                currentlexeme.clear();
                currentState = start;
            }
            currentState = start;
            position++;
            break;

        case state :: digitState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: integerFinal:
            add(currentlexeme, "Numlit");
            currentlexeme.clear();
            currentState = start;
            break;
        case state ::VariableState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: VariableFinal:
            add(currentlexeme, "variable");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: slashState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state::DivisorFinal:
            add(currentlexeme, "Divisor");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: commentState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: commentFinal:
            currentlexeme += ch;
            currentState = nextState;
            currentlexeme.clear();
            position++;
            break;
        case state :: equalsState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: assignmentFinal:   
            add(currentlexeme, "assignment");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: equalityFinal:
            currentlexeme += ch;
            add(currentlexeme, "equality");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: lessThanState:
            currentlexeme+= ch;
            currentState = nextState;
            position++;
            break;
        case state :: lessThanFinal:
            add(currentlexeme, "lessThan");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: lessThanEqualsStateFinal: 
            currentlexeme += ch;
            add(currentlexeme, "lessThanEquals");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: greaterThanState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: greaterThanFinal:
            add(currentlexeme, "greaterThan");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: greaterThanEqualsStateFinal:
            currentlexeme += ch;
            add(currentlexeme, "greaterThanEquals");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: exclemationState:
            currentlexeme += ch;
            currentState = nextState;
            position++;
            break;
        case state :: NotstateFinal:
            add(currentlexeme, "Not");
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: notEqualsStateFinal:
            currentlexeme += ch;
            add(currentlexeme, "notEquals");
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: delimiterState:
            currentlexeme += ch;
            if(ch == ',')
            {
                add(currentlexeme, "comma");
                currentlexeme.clear();
            }
            else if(ch == ';')
            {
                add(currentlexeme, "semicolon");
                currentlexeme.clear();
            }
            currentState = start;
            position++;
            break;
        case state :: braceState:
            currentlexeme += ch;
            if(ch == '{')
            {
                add(currentlexeme, "leftbrace");
                currentlexeme.clear();
            }
            else if(ch == '}')
            {
                add(currentlexeme, "rightbrace");
                currentlexeme.clear();
            }
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: parenState:
            currentlexeme += ch;
            if(ch == '(')
            {
                add(currentlexeme, "leftparen");
                currentlexeme.clear();
            }
            else if(ch == ')')
            {
                add(currentlexeme, "rightparen");
                currentlexeme.clear();
            }
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        default:
            break;
        }
    }   
}
