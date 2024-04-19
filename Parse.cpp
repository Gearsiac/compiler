#include <iostream>
#include <string>
#include <iomanip>
#include "lexical.h"
#include "Parse.h"
#include "symbol.h"
#include "States.h"
#include <stack>
using namespace std;

void Parse::PDAConfig()
{
    for(int i = 0; i < OPState; i++) // Loop through the states
    {
        for(int j = 0; j < OPInput; j++) // Loop through the inputs
        {
            PDAPrecedenceTable[i][j] = '?'; // Set the precedence to a space
        }
    }


        // Set the Terminator precedence
    PDAPrecedenceTable[ArnoldOP][AssignOp] = '<';
    PDAPrecedenceTable[ArnoldOP][LeftBraceOP] = '<';


    // Set the Assignment operator precedence
    PDAPrecedenceTable[AssignOp][ArnoldOP] = '>';
    PDAPrecedenceTable[AssignOp][ADDOP] = '<';
    PDAPrecedenceTable[AssignOp][SUBOP] = '<';
    PDAPrecedenceTable[AssignOp][LeftPrenOP] = '<';
    PDAPrecedenceTable[AssignOp][MulOP] = '<';
    PDAPrecedenceTable[AssignOp][DivOP] = '<';

    // Set the ADD operator precedence
    PDAPrecedenceTable[ADDOP][ArnoldOP] = '>';
    PDAPrecedenceTable[ADDOP][ADDOP] = '>';
    PDAPrecedenceTable[ADDOP][SUBOP] = '>';
    PDAPrecedenceTable[ADDOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[ADDOP][RightPrenOP] = '>';
    PDAPrecedenceTable[ADDOP][MulOP] = '<';
    PDAPrecedenceTable[ADDOP][DivOP] = '<';
    PDAPrecedenceTable[ADDOP][THENOP] = '>';
    PDAPrecedenceTable[ADDOP][EqualityOP] = '>';
    PDAPrecedenceTable[ADDOP][NotEqualOP] = '>';
    PDAPrecedenceTable[ADDOP][GreaterThanOP] = '>';
    PDAPrecedenceTable[ADDOP][LessThanOP] = '>';
    PDAPrecedenceTable[ADDOP][GreaterThanEqualOP] = '>';
    PDAPrecedenceTable[ADDOP][LessThanEqualOP] = '>';
    PDAPrecedenceTable[ADDOP][RightBraceOP] = '>';

    // Set the SUB operator precedence
    PDAPrecedenceTable[SUBOP][ArnoldOP] = '>';
    PDAPrecedenceTable[SUBOP][ADDOP] = '>';
    PDAPrecedenceTable[SUBOP][SUBOP] = '>';
    PDAPrecedenceTable[SUBOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[SUBOP][RightPrenOP] = '>';
    PDAPrecedenceTable[SUBOP][MulOP] = '<';
    PDAPrecedenceTable[SUBOP][DivOP] = '<';
    PDAPrecedenceTable[SUBOP][THENOP] = '>';
    PDAPrecedenceTable[SUBOP][EqualityOP] = '>';
    PDAPrecedenceTable[SUBOP][NotEqualOP] = '>';
    PDAPrecedenceTable[SUBOP][GreaterThanOP] = '>';
    PDAPrecedenceTable[SUBOP][LessThanOP] = '>';
    PDAPrecedenceTable[SUBOP][GreaterThanEqualOP] = '>';
    PDAPrecedenceTable[SUBOP][LessThanEqualOP] = '>';
    PDAPrecedenceTable[SUBOP][RightBraceOP] = '>';

    // Set the Left Parenthesis precedence
    PDAPrecedenceTable[LeftPrenOP][ADDOP] = '<';
    PDAPrecedenceTable[LeftPrenOP][SUBOP] = '<';
    PDAPrecedenceTable[LeftPrenOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[LeftPrenOP][RightPrenOP] = '=';
    PDAPrecedenceTable[LeftPrenOP][MulOP] = '<';
    PDAPrecedenceTable[LeftPrenOP][DivOP] = '<';


    // Set the Right Parenthesis precedence
    PDAPrecedenceTable[RightPrenOP][ArnoldOP] = '>';
    PDAPrecedenceTable[RightPrenOP][ADDOP] = '>';
    PDAPrecedenceTable[RightPrenOP][SUBOP] = '>';
    PDAPrecedenceTable[RightPrenOP][RightPrenOP] = '>';
    PDAPrecedenceTable[RightPrenOP][MulOP] = '>';
    PDAPrecedenceTable[RightPrenOP][DivOP] = '>';

    // Set the Multiplication operator precedence
    PDAPrecedenceTable[MulOP][ArnoldOP] = '>';
    PDAPrecedenceTable[MulOP][ADDOP] = '>';
    PDAPrecedenceTable[MulOP][SUBOP] = '>';
    PDAPrecedenceTable[MulOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[MulOP][RightPrenOP] = '>';
    PDAPrecedenceTable[MulOP][MulOP] = '>';
    PDAPrecedenceTable[MulOP][DivOP] = '>';
    PDAPrecedenceTable[MulOP][THENOP] = '>';
    PDAPrecedenceTable[MulOP][EqualityOP] = '>';
    PDAPrecedenceTable[MulOP][NotEqualOP] = '>';
    PDAPrecedenceTable[MulOP][GreaterThanOP] = '>';
    PDAPrecedenceTable[MulOP][LessThanOP] = '>';
    PDAPrecedenceTable[MulOP][GreaterThanEqualOP] = '>';
    PDAPrecedenceTable[MulOP][LessThanEqualOP] = '>';
    PDAPrecedenceTable[MulOP][RightBraceOP] = '>';


    // Set the Division operator precedence
    PDAPrecedenceTable[DivOP][ArnoldOP] = '>';
    PDAPrecedenceTable[DivOP][ADDOP] = '>';
    PDAPrecedenceTable[DivOP][SUBOP] = '>';
    PDAPrecedenceTable[DivOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[DivOP][RightPrenOP] = '>';
    PDAPrecedenceTable[DivOP][MulOP] = '>'; 
    PDAPrecedenceTable[DivOP][DivOP] = '>';
    PDAPrecedenceTable[DivOP][THENOP] = '>';
    PDAPrecedenceTable[DivOP][EqualityOP] = '>';
    PDAPrecedenceTable[DivOP][NotEqualOP] = '>';
    PDAPrecedenceTable[DivOP][GreaterThanOP] = '>';
    PDAPrecedenceTable[DivOP][LessThanOP] = '>';
    PDAPrecedenceTable[DivOP][GreaterThanEqualOP] = '>';
    PDAPrecedenceTable[DivOP][LessThanEqualOP] = '>';
    PDAPrecedenceTable[DivOP][RightBraceOP] = '>';


    // Set the IF operator precedence
    PDAPrecedenceTable[IFOP][ADDOP] = '<';
    PDAPrecedenceTable[IFOP][SUBOP] = '<';
    PDAPrecedenceTable[IFOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[IFOP][MulOP] = '<';
    PDAPrecedenceTable[IFOP][DivOP] = '<';
    PDAPrecedenceTable[IFOP][THENOP] = '=';
    PDAPrecedenceTable[IFOP][ODDOP] = '<';
    PDAPrecedenceTable[IFOP][EqualityOP] = '<';
    PDAPrecedenceTable[IFOP][NotEqualOP] = '<';
    PDAPrecedenceTable[IFOP][GreaterThanOP] = '<';
    PDAPrecedenceTable[IFOP][LessThanOP] = '<';
    PDAPrecedenceTable[IFOP][GreaterThanEqualOP] = '<';
    PDAPrecedenceTable[IFOP][LessThanEqualOP] = '<';


    // Set the THEN operator precedence
    PDAPrecedenceTable[THENOP][AssignOp] = '<';
    PDAPrecedenceTable[THENOP][IFOP] = '<';
    PDAPrecedenceTable[THENOP][ElseOP] = '=';
    PDAPrecedenceTable[THENOP][WhileOP] = '<';
    PDAPrecedenceTable[THENOP][LeftBraceOP] = '<';
    PDAPrecedenceTable[THENOP][CallOP] = '<';


    // Set the ELSE operator precedence
    PDAPrecedenceTable[ElseOP][AssignOp] = '<';
    PDAPrecedenceTable[ElseOP][IFOP] = '<';
    PDAPrecedenceTable[ElseOP][WhileOP] = '<';
    PDAPrecedenceTable[ElseOP][LeftBraceOP] = '<';
    PDAPrecedenceTable[ElseOP][CallOP] = '<';


    // Set the WHILE operator precedence
    PDAPrecedenceTable[WhileOP][ADDOP] = '<';
    PDAPrecedenceTable[WhileOP][SUBOP] = '<';
    PDAPrecedenceTable[WhileOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[WhileOP][MulOP] = '<';
    PDAPrecedenceTable[WhileOP][DivOP] = '<';
    PDAPrecedenceTable[WhileOP][DoOP] = '=';
    PDAPrecedenceTable[WhileOP][ODDOP] = '<';
    PDAPrecedenceTable[WhileOP][EqualityOP] = '<';
    PDAPrecedenceTable[WhileOP][NotEqualOP] = '<';
    PDAPrecedenceTable[WhileOP][GreaterThanOP] = '<';
    PDAPrecedenceTable[WhileOP][LessThanOP] = '<';
    PDAPrecedenceTable[WhileOP][GreaterThanEqualOP] = '<';
    PDAPrecedenceTable[WhileOP][LessThanEqualOP] = '<';


    // Set the DO operator precedence
    PDAPrecedenceTable[DoOP][AssignOp] = '<';
    PDAPrecedenceTable[DoOP][WhileOP] = '<';
    PDAPrecedenceTable[DoOP][RightBraceOP] = '<';
    PDAPrecedenceTable[DoOP][CallOP] = '<';


    // Set the ODD operator precedence
    PDAPrecedenceTable[ODDOP][ADDOP] = '<';
    PDAPrecedenceTable[ODDOP][SUBOP] = '<';
    PDAPrecedenceTable[ODDOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[ODDOP][MulOP] = '<';
    PDAPrecedenceTable[ODDOP][DivOP] = '<';
    PDAPrecedenceTable[ODDOP][THENOP] = '>';


    // Set the Equality operator precedence
    PDAPrecedenceTable[EqualityOP][ADDOP] = '<';
    PDAPrecedenceTable[EqualityOP][SUBOP] = '<';
    PDAPrecedenceTable[EqualityOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[EqualityOP][MulOP] = '<';
    PDAPrecedenceTable[EqualityOP][DivOP] = '<';
    PDAPrecedenceTable[EqualityOP][THENOP] = '>';


    // Set the Not Equal operator precedence
    PDAPrecedenceTable[NotEqualOP][ADDOP] = '<';
    PDAPrecedenceTable[NotEqualOP][SUBOP] = '<';
    PDAPrecedenceTable[NotEqualOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[NotEqualOP][MulOP] = '<';
    PDAPrecedenceTable[NotEqualOP][DivOP] = '<';
    PDAPrecedenceTable[NotEqualOP][THENOP] = '>';


    // Set the Greater Than operator precedence
    PDAPrecedenceTable[GreaterThanOP][ADDOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][SUBOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][MulOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][DivOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][THENOP] = '>';


    // Set the Less Than operator precedence
    PDAPrecedenceTable[LessThanOP][ADDOP] = '<';
    PDAPrecedenceTable[LessThanOP][SUBOP] = '<';
    PDAPrecedenceTable[LessThanOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[LessThanOP][MulOP] = '<';
    PDAPrecedenceTable[LessThanOP][DivOP] = '<';
    PDAPrecedenceTable[LessThanOP][THENOP] = '>';


    // Set the Greater Than Equal operator precedence
    PDAPrecedenceTable[GreaterThanEqualOP][ADDOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][SUBOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][MulOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][DivOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][THENOP] = '>';


    // Set the Less Than Equal operator precedence
    PDAPrecedenceTable[LessThanEqualOP][ADDOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][SUBOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][MulOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][DivOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][THENOP] = '>';


    // Set the Left Brace operator precedence
    PDAPrecedenceTable[LeftBraceOP][AssignOp] = '<';
    PDAPrecedenceTable[LeftBraceOP][IFOP] = '<';
    PDAPrecedenceTable[LeftBraceOP][WhileOP] = '<';
    PDAPrecedenceTable[LeftBraceOP][LeftBraceOP] = '<';
    PDAPrecedenceTable[LeftBraceOP][RightBraceOP] = '=';
    PDAPrecedenceTable[LeftBraceOP][CallOP] = '<';

}
ParseOps Parse::ParseMap(const Tokens &token) // Parse map
{
    if(token.lexeme == ";" || token.lexeme == "%") return ArnoldOP; // Return the Arnold operator
    if(token.lexeme == "=") return AssignOp; // Return the Assignment operator
    if(token.lexeme == "+") return ADDOP; // Return the ADD operator
    if(token.lexeme == "-") return SUBOP; // Return the SUB operator
    if(token.lexeme == "(") return LeftPrenOP; // Return the Left Parenthesis operator
    if(token.lexeme == ")") return RightPrenOP; // Return the Right Parenthesis operator
    if(token.lexeme == "*") return MulOP; // Return the Multiplication operator
    if(token.lexeme == "/") return DivOP; // Return the Division operator
    if(token.lexeme == "IF" || token.lexeme == "if") return IFOP;   // Return the IF operator
    if(token.lexeme == "THEN" || token.lexeme == "then") return THENOP; // Return the THEN operator
    if(token.lexeme == "ELSE" || token.lexeme == "else") return ElseOP; // Return the ELSE operator
    if(token.lexeme == "WHILE" || token.lexeme == "while") return WhileOP; // Return the WHILE operator
    if(token.lexeme == "DO" || token.lexeme == "do") return DoOP; // Return the DO operator
    if(token.lexeme == "ODD" || token.lexeme == "odd") return ODDOP; // Return the ODD operator
    if(token.lexeme == "CALL" || token.lexeme == "call") return CallOP; // Return the CALL operator
    if(token.lexeme == "==") return EqualityOP; // Return the Equality operator
    if(token.lexeme == "!=") return NotEqualOP; // Return the Not Equal operator
    if(token.lexeme == ">") return GreaterThanOP; // Return the Greater Than operator
    if(token.lexeme == "<") return LessThanOP; // Return the Less Than operator
    if(token.lexeme == ">=") return GreaterThanEqualOP; // Return the Greater Than Equal operator
    if(token.lexeme == "<=") return LessThanEqualOP; // Return the Less Than Equal operator
    if(token.lexeme == "{") return LeftBraceOP; // Return the Left Brace operator
    if(token.lexeme == "}") return RightBraceOP; // Return the Right Brace operator
    return NonOP; // Return the Non operator for everything else

}
Quads :: Quads(const string& op, const string& arg1, const string& arg2, const string& Temp) :
op(op), arg1(arg1), arg2(arg2), Temp(Temp){} // Constructor

Parse :: Parse() // Constructor
{
    StackCount = 0; // Set the Parse stack count to 0
    QuadsCount = 0; // Set the Parse quads count to 0
    PDAConfig(); // Configure the PDA
}
char Parse :: ReadRowsAndCollums(ParseOps currentState, ParseOps input) // Read rows and collums
{
    return PDAPrecedenceTable[currentState][input]; 

}
size_t Parse :: getQuadsCount() const // Get the Parse quads count
{
    return QuadsCount; // Return the Parse quads count
}
Quads* Parse :: getParseQuads() // Get the Parse quads
{
    return *ParseQuads; // Return the Parse quads
}
void Parse :: AddToQuads(const string& op = "?", const string& arg1 = "?", const string& arg2 = "?", const string& Temp = "?") // Add to the Parse quads
{
    ParseQuads[QuadsCount++] = new Quads(op, arg1, arg2, Temp); // Add to the Parse quads
    
}


void Parse::Parseing(const Tokens& token, Tokens* tokens, int tokenCount) // Stack handling 
{
    Tokens CurrentToken, TopToken;
    ParseOps CurrentOPS, TopOPSDrops;
    ParseStack[StackCount++] = new Tokens("%", "T101");
    for(int i = 0; i < tokenCount; i++) // Loop through the tokens
    {
        bool Parsing = false;
        CurrentToken = tokens[i]; // Get the token
        CurrentOPS = ParseMap(token); // Get the input
        TopOPSDrops; // Get the top ops that drop
        char Relation = ReadRowsAndCollums(TopOPSDrops, CurrentOPS);
        cout << "Processing Token: " << tokens[i].lexeme << endl;
        for(int i = 0; i < tokenCount; i++)
        {
            if(tokens[i].lexeme == "CLASS" || "class")
            {
                cout << "skipping Token: " << tokens[i].lexeme << endl;
                i++;
                continue;
            }
            if(tokens[i].tokenType == "Variable")
            {
                cout << "skipping Token: " << tokens[i].lexeme << endl;
                i++;
                Parsing = true;
            }
            

        }
        

    }
}
