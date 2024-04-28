#include <string>
#include <iostream>
#include <string>
#include "lexical.h"
#include "EnumerationTypes.h"
using namespace std;
void Lexical::LexicalFSA() // Function to configure the FSA
{

    // 2D array of states and types
StateTransitionTable[start][letter] = VariableState;
StateTransitionTable[start][digit] = digitState;
StateTransitionTable[start][astrix] = operation;
StateTransitionTable[start][plusType] = operation;
StateTransitionTable[start][minusType] = operation;
StateTransitionTable[start][divisor] = slashState;
StateTransitionTable[start][equals] = equalsState;
StateTransitionTable[start][lessThan] = lessThanState;
StateTransitionTable[start][greaterThan] = greaterThanState;
StateTransitionTable[start][exlimation] = exclemationState;
StateTransitionTable[start][leftparen] = parenState;
StateTransitionTable[start][rightparen] = parenState;
StateTransitionTable[start][leftbrace] = braceState;
StateTransitionTable[start][rightbrace] = braceState;
StateTransitionTable[start][comma] = delimiterState;
StateTransitionTable[start][semicolon] = delimiterState;
StateTransitionTable[start][WS] = start;
StateTransitionTable[start][other] = error;

//digit state
StateTransitionTable[digitState][letter] = integerFinal;
StateTransitionTable[digitState][digit] = digitState;
StateTransitionTable[digitState][astrix] = integerFinal;
StateTransitionTable[digitState][plusType] = integerFinal;
StateTransitionTable[digitState][minusType] = integerFinal;
StateTransitionTable[digitState][divisor] = integerFinal;
StateTransitionTable[digitState][equals] = integerFinal;
StateTransitionTable[digitState][lessThan] = integerFinal;
StateTransitionTable[digitState][greaterThan] = integerFinal;
StateTransitionTable[digitState][exlimation] = integerFinal;
StateTransitionTable[digitState][leftparen] = integerFinal;
StateTransitionTable[digitState][rightparen] = integerFinal;
StateTransitionTable[digitState][leftbrace] = integerFinal;
StateTransitionTable[digitState][rightbrace] = integerFinal;
StateTransitionTable[digitState][comma] = integerFinal;
StateTransitionTable[digitState][semicolon] = integerFinal;
StateTransitionTable[digitState][WS] = integerFinal;
StateTransitionTable[digitState][other] = error;


//Variable state
StateTransitionTable[VariableState][letter] = VariableState;
StateTransitionTable[VariableState][digit] = VariableState;
StateTransitionTable[VariableState][astrix] = VariableFinal;
StateTransitionTable[VariableState][plusType] = VariableFinal;
StateTransitionTable[VariableState][minusType] = VariableFinal;
StateTransitionTable[VariableState][divisor] = VariableFinal;
StateTransitionTable[VariableState][equals] = VariableFinal;
StateTransitionTable[VariableState][lessThan] = VariableFinal;
StateTransitionTable[VariableState][greaterThan] = VariableFinal;
StateTransitionTable[VariableState][exlimation] = VariableFinal;
StateTransitionTable[VariableState][leftparen] = VariableFinal;
StateTransitionTable[VariableState][rightparen] = VariableFinal;
StateTransitionTable[VariableState][leftbrace] = VariableFinal;
StateTransitionTable[VariableState][rightbrace] = VariableFinal;
StateTransitionTable[VariableState][comma] = VariableFinal;
StateTransitionTable[VariableState][semicolon] = VariableFinal;
StateTransitionTable[VariableState][WS] = VariableFinal;
StateTransitionTable[VariableState][other] = error;


//slash state
StateTransitionTable[slashState][letter] = DivisorFinal;
StateTransitionTable[slashState][digit] = DivisorFinal;
StateTransitionTable[slashState][astrix] = commentState;
StateTransitionTable[slashState][plusType] = DivisorFinal;
StateTransitionTable[slashState][minusType] = DivisorFinal;
StateTransitionTable[slashState][divisor] = DivisorFinal;
StateTransitionTable[slashState][equals] = DivisorFinal;
StateTransitionTable[slashState][lessThan] = DivisorFinal;
StateTransitionTable[slashState][greaterThan] = DivisorFinal;
StateTransitionTable[slashState][exlimation] = DivisorFinal;
StateTransitionTable[slashState][leftparen] = DivisorFinal;
StateTransitionTable[slashState][rightparen] = DivisorFinal;
StateTransitionTable[slashState][leftbrace] = DivisorFinal;
StateTransitionTable[slashState][rightbrace] = DivisorFinal;
StateTransitionTable[slashState][comma] = DivisorFinal;
StateTransitionTable[slashState][semicolon] = DivisorFinal;
StateTransitionTable[slashState][WS] = DivisorFinal;
StateTransitionTable[slashState][other] = error;

//comment state
StateTransitionTable[commentState][letter] = commentState;
StateTransitionTable[commentState][digit] = commentState;
StateTransitionTable[commentState][astrix] = commentFinal;
StateTransitionTable[commentState][plusType] = commentState;
StateTransitionTable[commentState][minusType] = commentState;
StateTransitionTable[commentState][divisor] = commentState;
StateTransitionTable[commentState][equals] = commentState;
StateTransitionTable[commentState][lessThan] = commentState;
StateTransitionTable[commentState][greaterThan] = commentState;
StateTransitionTable[commentState][exlimation] = commentState;
StateTransitionTable[commentState][leftparen] = commentState;
StateTransitionTable[commentState][rightparen] = commentState;
StateTransitionTable[commentState][leftbrace] = commentState;
StateTransitionTable[commentState][rightbrace] = commentState;
StateTransitionTable[commentState][comma] = commentState;
StateTransitionTable[commentState][semicolon] = commentState;
StateTransitionTable[commentState][WS] = commentState;

StateTransitionTable[commentFinal][letter] = commentState;
StateTransitionTable[commentFinal][digit] = commentState;
StateTransitionTable[commentFinal][astrix] = commentState;
StateTransitionTable[commentFinal][plusType] = commentState;
StateTransitionTable[commentFinal][minusType] = commentState;
StateTransitionTable[commentFinal][divisor] = start;
StateTransitionTable[commentFinal][equals] = commentState;
StateTransitionTable[commentFinal][lessThan] = commentState;
StateTransitionTable[commentFinal][greaterThan] = commentState;
StateTransitionTable[commentFinal][exlimation] = commentState;
StateTransitionTable[commentFinal][leftparen] = commentState;
StateTransitionTable[commentFinal][rightparen] = commentState;
StateTransitionTable[commentFinal][leftbrace] = commentState;
StateTransitionTable[commentFinal][rightbrace] = commentState;
StateTransitionTable[commentFinal][comma] = commentState;
StateTransitionTable[commentFinal][semicolon] = commentState;
StateTransitionTable[commentFinal][WS] = commentState;

//equals state
StateTransitionTable[equalsState][letter] = assignmentFinal;
StateTransitionTable[equalsState][digit] = assignmentFinal;
StateTransitionTable[equalsState][astrix] = assignmentFinal;
StateTransitionTable[equalsState][plusType] = assignmentFinal;
StateTransitionTable[equalsState][minusType] = assignmentFinal;
StateTransitionTable[equalsState][divisor] = assignmentFinal;
StateTransitionTable[equalsState][equals] = equalityFinal;
StateTransitionTable[equalsState][lessThan] = assignmentFinal;
StateTransitionTable[equalsState][greaterThan] = assignmentFinal;
StateTransitionTable[equalsState][exlimation] = assignmentFinal;
StateTransitionTable[equalsState][leftparen] = assignmentFinal;
StateTransitionTable[equalsState][rightparen] = assignmentFinal;
StateTransitionTable[equalsState][leftbrace] = assignmentFinal;
StateTransitionTable[equalsState][rightbrace] = assignmentFinal;
StateTransitionTable[equalsState][comma] = assignmentFinal;
StateTransitionTable[equalsState][semicolon] = assignmentFinal;
StateTransitionTable[equalsState][WS] = assignmentFinal;
StateTransitionTable[equalsState][other] = error;

//less than state
StateTransitionTable[lessThanState][letter] = lessThanFinal;
StateTransitionTable[lessThanState][digit] = lessThanFinal;
StateTransitionTable[lessThanState][astrix] = lessThanFinal;
StateTransitionTable[lessThanState][plusType] = lessThanFinal;
StateTransitionTable[lessThanState][minusType] = lessThanFinal;
StateTransitionTable[lessThanState][divisor] = lessThanFinal;
StateTransitionTable[lessThanState][equals] = lessThanEqualsStateFinal;
StateTransitionTable[lessThanState][lessThan] = lessThanState;
StateTransitionTable[lessThanState][greaterThan] = lessThanFinal;
StateTransitionTable[lessThanState][exlimation] = lessThanFinal;
StateTransitionTable[lessThanState][leftparen] = lessThanFinal;
StateTransitionTable[lessThanState][rightparen] = lessThanFinal;
StateTransitionTable[lessThanState][leftbrace] = lessThanFinal;
StateTransitionTable[lessThanState][rightbrace] = lessThanFinal;
StateTransitionTable[lessThanState][comma] = lessThanFinal;
StateTransitionTable[lessThanState][semicolon] = lessThanFinal;
StateTransitionTable[lessThanState][WS] = lessThanFinal;
StateTransitionTable[lessThanState][other] = error;

//greater than state
StateTransitionTable[greaterThanState][letter] = greaterThanFinal;
StateTransitionTable[greaterThanState][digit] = greaterThanFinal;
StateTransitionTable[greaterThanState][astrix] = greaterThanFinal;
StateTransitionTable[greaterThanState][plusType] = greaterThanFinal;
StateTransitionTable[greaterThanState][minusType] = greaterThanFinal;
StateTransitionTable[greaterThanState][divisor] = greaterThanFinal;
StateTransitionTable[greaterThanState][equals] = greaterThanEqualsStateFinal;
StateTransitionTable[greaterThanState][lessThan] = greaterThanFinal;
StateTransitionTable[greaterThanState][greaterThan] = greaterThanState;
StateTransitionTable[greaterThanState][exlimation] = greaterThanFinal;
StateTransitionTable[greaterThanState][leftparen] = greaterThanFinal;
StateTransitionTable[greaterThanState][rightparen] = greaterThanFinal;
StateTransitionTable[greaterThanState][leftbrace] = greaterThanFinal;
StateTransitionTable[greaterThanState][rightbrace] = greaterThanFinal;
StateTransitionTable[greaterThanState][comma] = greaterThanFinal;
StateTransitionTable[greaterThanState][semicolon] = greaterThanFinal;
StateTransitionTable[greaterThanState][WS] = greaterThanFinal;
StateTransitionTable[greaterThanState][other] = error;

//exclemation state
StateTransitionTable[exclemationState][letter] = NotstateFinal;
StateTransitionTable[exclemationState][digit] = NotstateFinal;
StateTransitionTable[exclemationState][astrix] = NotstateFinal;
StateTransitionTable[exclemationState][plusType] = NotstateFinal;
StateTransitionTable[exclemationState][minusType] = NotstateFinal;
StateTransitionTable[exclemationState][divisor] = NotstateFinal;
StateTransitionTable[exclemationState][equals] = notEqualsStateFinal;
StateTransitionTable[exclemationState][lessThan] = NotstateFinal;
StateTransitionTable[exclemationState][greaterThan] = NotstateFinal;
StateTransitionTable[exclemationState][exlimation] = NotstateFinal;
StateTransitionTable[exclemationState][leftparen] = NotstateFinal;
StateTransitionTable[exclemationState][rightparen] = NotstateFinal;
StateTransitionTable[exclemationState][leftbrace] = NotstateFinal;
StateTransitionTable[exclemationState][rightbrace] = NotstateFinal;
StateTransitionTable[exclemationState][comma] = NotstateFinal;
StateTransitionTable[exclemationState][semicolon] = NotstateFinal;
StateTransitionTable[exclemationState][WS] = NotstateFinal;
StateTransitionTable[exclemationState][other] = error;
}
Lexical::Lexical() // Constructor for Lexical class
{
    LexicalFSA(); // Configure the FSA
}
state Lexical::ReadRowsAndCollums(state currentState, types input) // Function to read the rows and collums of the table
{
    int NextStateTransition = StateTransitionTable[currentState][input]; // Get the next state transition
    return static_cast<state>(NextStateTransition); // Return the next state transition
}

Tokens::Tokens(const string& lexeme, const string& tokenType) : 
lexeme(lexeme), tokenType(tokenType){} // Constructor for Tokens class

void Lexical::AddToTokenList(const string& lexeme, const string& tokenType) // Function to add to the token list
{
    tokens[tokenCount++] = Tokens(lexeme, tokenType); // Add the lexeme and token type to the token list
}

void Lexical::setInput(const string& ins) // Function to set the input
{
    input = ins; // Set the input to the input string
    position = 0; // Set the position to 0
    tokenCount = 0; // Set the token count to 0
}

types Lexical::getChType(char ch) // Function to get the type of character
{
    switch (ch)
    {
    case '*':
      return types ::astrix;
    case '+':
        return types :: plusType;
    case '-':
        return types :: minusType;
    case '/':
        return types ::divisor;
    case '=':
        return types :: equals;
    case '<':
        return types :: lessThan;
    case '>':
        return types :: greaterThan;
    case '!':
        return types :: exlimation;
    case '(':
        return types :: leftparen;
    case ')':
        return types :: rightparen;
    case '{':
        return types :: leftbrace;
    case '}':
        return types :: rightbrace;
    case ',':
        return types :: comma;
    case ';':
        return types :: semicolon;
    default:
        if(isalpha(ch)){
            return types::letter;
        }
        else if(isdigit(ch)){
            return types::digit;
        }
        else if(isspace(ch)){
            return types :: WS;
        }
        else {
            return types :: other;
        }
        break;
    }
}
string Lexical::IdentifyToken(state State, const string& lexeme) const // Function to map the token
{
    switch (State)
    {
    case state::operation:
        if(lexeme == "*") return "MOP";
        if(lexeme == "+") return "ADDOP";
        if(lexeme == "-")  return "SUBOP";
    case state::integerFinal:
        return "Numlit";
        case state::VariableFinal:
        if(lexeme == "CONST" || lexeme == "const") return "RESERVED WORD";
        if(lexeme == "VAR" || lexeme == "var") return "RESERVED WORD";
        if(lexeme == "IF" || lexeme == "if") return "RESERVED WORD";
        if(lexeme == "THEN" || lexeme == "then") return "RESERVED WORD";
        if(lexeme == "ELSE" || lexeme == "else") return "RESERVED WORD";
        if(lexeme == "WHILE" || lexeme == "while") return "RESERVED WORD";
        if(lexeme == "DO" || lexeme == "do") return "RESERVED WORD";
        if(lexeme == "PROCEDURE" || lexeme == "procedure") return "RESERVED WORD";
        if(lexeme == "ODD" || lexeme == "odd") return "RESERVED WORD";
        if(lexeme == "CALL" || lexeme == "call") return "RESERVED WORD";
        if(lexeme == "CLASS" || lexeme == "class") return "RESERVED WORD";
        if(lexeme == "CIN" || lexeme == "cin") return "RESERVED WORD";
        if(lexeme == "COUT" || lexeme == "cout") return "RESERVED WORD";
        return "Variable";
    case state::DivisorFinal:
        return "DIVOP";
    case state::assignmentFinal:
        return "assignment";
    case state::equalityFinal:
        return "equality";
    case state::lessThanFinal:
        return "lessThan";
    case state::lessThanEqualsStateFinal:
        return "lessThanEquals";
    case state::greaterThanFinal:
        return "greaterThan";
    case state::greaterThanEqualsStateFinal:
        return "greaterThanEquals";
    case state::NotstateFinal:
        return "Not";
    case state::notEqualsStateFinal:
        return "notEquals";
    case state::delimiterState:
        if(lexeme == ",") return "comma";
        if(lexeme == ";") return "semicolon";
    case state::braceState:
        if(lexeme == "{") return "leftbrace";
        if(lexeme == "}") return "rightbrace";
    case state::parenState:
        if(lexeme == "(") return "leftparen";
        if(lexeme == ")") return "rightparen";
    default:
        return "error";
    }
};
Tokens* Lexical::getTokens() // Function to get the tokens
{
    return tokens; // Return the tokens
}
int Lexical::getTokenCount() const // Function to get the token count
{
    return tokenCount; // Return the token count
}
void Lexical::tokenize(const string& ins) // Function to tokenize the input
{
    state currentState = start; // Set the current state to start
    state NextStateTransition; // Set the next state transition
    string currentlexeme; // Set the current lexeme
    while(position < ins.length()) // While the position is less than the length of the input
    {
        char ch = ins[position]; // Get the character at the position
        types chType = getChType(ch); // Get the type of character
        NextStateTransition = ReadRowsAndCollums(currentState, chType); // Get the next state
        switch (NextStateTransition) // Switch statement for the next state transition
        {
        case state::start:
            currentState = NextStateTransition;
            position++;
            break;
        case state ::error:
            currentState = start;
            currentlexeme.clear();
            position++;
            break;
        case state ::operation:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: digitState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: integerFinal:
            AddToTokenList("Lit" + currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state ::VariableState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: VariableFinal:
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: slashState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state::DivisorFinal:
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: commentState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: commentFinal:
            currentlexeme += ch;
            currentState = NextStateTransition;
            currentlexeme.clear();
            position++;
            break;
        case state :: equalsState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: assignmentFinal:   
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: equalityFinal:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: lessThanState:
            currentlexeme+= ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: lessThanFinal:
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: lessThanEqualsStateFinal: 
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: greaterThanState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: greaterThanFinal:
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: greaterThanEqualsStateFinal:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: exclemationState:
            currentlexeme += ch;
            currentState = NextStateTransition;
            position++;
            break;
        case state :: NotstateFinal:
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            break;
        case state :: notEqualsStateFinal:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: delimiterState:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: braceState:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        case state :: parenState:
            currentlexeme += ch;
            AddToTokenList(currentlexeme, IdentifyToken(NextStateTransition, currentlexeme ));
            currentlexeme.clear();
            currentState = start;
            position++;
            break;
        default:
            break;
        }
    }   
    AddToTokenList("EOF", "EOF"); // Add EOF to the token list
}
