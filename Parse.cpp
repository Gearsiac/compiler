#include <iostream>
#include <string>
#include <iomanip>
#include "lexical.h"
#include "Parse.h"
#include "symbol.h"
#include "States.h"
using namespace std;

void Parse::PDAConfig()
{
    for(int i = 0; i < OPState; i++) // Loop through the states
    {
        for(int j = 0; j < OPInput; j++) // Loop through the inputs
        {
            PDAPrecedence[i][j] = '?'; // Set the precedence to a space
        }
    }

    
        // Set the Terminator precedence
    PDAPrecedence[ArnoldOP][AssignOp] = '<';
    PDAPrecedence[ArnoldOP][LeftBraceOP] = '<';


    // Set the Assignment operator precedence
    PDAPrecedence[AssignOp][ArnoldOP] = '>';
    PDAPrecedence[AssignOp][ADDOP] = '<';
    PDAPrecedence[AssignOp][SUBOP] = '<';
    PDAPrecedence[AssignOp][LeftPrenOP] = '<';
    PDAPrecedence[AssignOp][MulOP] = '<';
    PDAPrecedence[AssignOp][DivOP] = '<';

    // Set the ADD operator precedence
    PDAPrecedence[ADDOP][ArnoldOP] = '>';
    PDAPrecedence[ADDOP][ADDOP] = '>';
    PDAPrecedence[ADDOP][SUBOP] = '>';
    PDAPrecedence[ADDOP][LeftPrenOP] = '<';
    PDAPrecedence[ADDOP][RightPrenOP] = '>';
    PDAPrecedence[ADDOP][MulOP] = '<';
    PDAPrecedence[ADDOP][DivOP] = '<';
    PDAPrecedence[ADDOP][THENOP] = '>';
    PDAPrecedence[ADDOP][EqualityOP] = '>';
    PDAPrecedence[ADDOP][NotEqualOP] = '>';
    PDAPrecedence[ADDOP][GreaterThanOP] = '>';
    PDAPrecedence[ADDOP][LessThanOP] = '>';
    PDAPrecedence[ADDOP][GreaterThanEqualOP] = '>';
    PDAPrecedence[ADDOP][LessThanEqualOP] = '>';
    PDAPrecedence[ADDOP][RightBraceOP] = '>';

    // Set the SUB operator precedence
    PDAPrecedence[SUBOP][ArnoldOP] = '>';
    PDAPrecedence[SUBOP][ADDOP] = '>';
    PDAPrecedence[SUBOP][SUBOP] = '>';
    PDAPrecedence[SUBOP][LeftPrenOP] = '<';
    PDAPrecedence[SUBOP][RightPrenOP] = '>';
    PDAPrecedence[SUBOP][MulOP] = '<';
    PDAPrecedence[SUBOP][DivOP] = '<';
    PDAPrecedence[SUBOP][THENOP] = '>';
    PDAPrecedence[SUBOP][EqualityOP] = '>';
    PDAPrecedence[SUBOP][NotEqualOP] = '>';
    PDAPrecedence[SUBOP][GreaterThanOP] = '>';
    PDAPrecedence[SUBOP][LessThanOP] = '>';
    PDAPrecedence[SUBOP][GreaterThanEqualOP] = '>';
    PDAPrecedence[SUBOP][LessThanEqualOP] = '>';
    PDAPrecedence[SUBOP][RightBraceOP] = '>';

    // Set the Left Parenthesis precedence
    PDAPrecedence[LeftPrenOP][ADDOP] = '<';
    PDAPrecedence[LeftPrenOP][SUBOP] = '<';
    PDAPrecedence[LeftPrenOP][LeftPrenOP] = '<';
    PDAPrecedence[LeftPrenOP][RightPrenOP] = '=';
    PDAPrecedence[LeftPrenOP][MulOP] = '<';
    PDAPrecedence[LeftPrenOP][DivOP] = '<';


    // Set the Right Parenthesis precedence
    PDAPrecedence[RightPrenOP][ArnoldOP] = '>';
    PDAPrecedence[RightPrenOP][ADDOP] = '>';
    PDAPrecedence[RightPrenOP][SUBOP] = '>';
    PDAPrecedence[RightPrenOP][RightPrenOP] = '>';
    PDAPrecedence[RightPrenOP][MulOP] = '>';
    PDAPrecedence[RightPrenOP][DivOP] = '>';

    // Set the Multiplication operator precedence
    PDAPrecedence[MulOP][ArnoldOP] = '>';
    PDAPrecedence[MulOP][ADDOP] = '>';
    PDAPrecedence[MulOP][SUBOP] = '>';
    PDAPrecedence[MulOP][LeftPrenOP] = '<';
    PDAPrecedence[MulOP][RightPrenOP] = '>';
    PDAPrecedence[MulOP][MulOP] = '>';
    PDAPrecedence[MulOP][DivOP] = '>';
    PDAPrecedence[MulOP][THENOP] = '>';
    PDAPrecedence[MulOP][EqualityOP] = '>';
    PDAPrecedence[MulOP][NotEqualOP] = '>';
    PDAPrecedence[MulOP][GreaterThanOP] = '>';
    PDAPrecedence[MulOP][LessThanOP] = '>';
    PDAPrecedence[MulOP][GreaterThanEqualOP] = '>';
    PDAPrecedence[MulOP][LessThanEqualOP] = '>';
    PDAPrecedence[MulOP][RightBraceOP] = '>';


    // Set the Division operator precedence
    PDAPrecedence[DivOP][ArnoldOP] = '>';
    PDAPrecedence[DivOP][ADDOP] = '>';
    PDAPrecedence[DivOP][SUBOP] = '>';
    PDAPrecedence[DivOP][LeftPrenOP] = '<';
    PDAPrecedence[DivOP][RightPrenOP] = '>';
    PDAPrecedence[DivOP][MulOP] = '>'; 
    PDAPrecedence[DivOP][DivOP] = '>';
    PDAPrecedence[DivOP][THENOP] = '>';
    PDAPrecedence[DivOP][EqualityOP] = '>';
    PDAPrecedence[DivOP][NotEqualOP] = '>';
    PDAPrecedence[DivOP][GreaterThanOP] = '>';
    PDAPrecedence[DivOP][LessThanOP] = '>';
    PDAPrecedence[DivOP][GreaterThanEqualOP] = '>';
    PDAPrecedence[DivOP][LessThanEqualOP] = '>';
    PDAPrecedence[DivOP][RightBraceOP] = '>';


    // Set the IF operator precedence
    PDAPrecedence[IFOP][ADDOP] = '<';
    PDAPrecedence[IFOP][SUBOP] = '<';
    PDAPrecedence[IFOP][LeftPrenOP] = '<';
    PDAPrecedence[IFOP][MulOP] = '<';
    PDAPrecedence[IFOP][DivOP] = '<';
    PDAPrecedence[IFOP][THENOP] = '=';
    PDAPrecedence[IFOP][ODDOP] = '<';
    PDAPrecedence[IFOP][EqualityOP] = '<';
    PDAPrecedence[IFOP][NotEqualOP] = '<';
    PDAPrecedence[IFOP][GreaterThanOP] = '<';
    PDAPrecedence[IFOP][LessThanOP] = '<';
    PDAPrecedence[IFOP][GreaterThanEqualOP] = '<';
    PDAPrecedence[IFOP][LessThanEqualOP] = '<';


    // Set the THEN operator precedence
    PDAPrecedence[THENOP][AssignOp] = '<';
    PDAPrecedence[THENOP][IFOP] = '<';
    PDAPrecedence[THENOP][ElseOP] = '=';
    PDAPrecedence[THENOP][WhileOP] = '<';
    PDAPrecedence[THENOP][LeftBraceOP] = '<';
    PDAPrecedence[THENOP][CallOP] = '<';


    // Set the ELSE operator precedence
    PDAPrecedence[ElseOP][AssignOp] = '<';
    PDAPrecedence[ElseOP][IFOP] = '<';
    PDAPrecedence[ElseOP][WhileOP] = '<';
    PDAPrecedence[ElseOP][LeftBraceOP] = '<';
    PDAPrecedence[ElseOP][CallOP] = '<';


    // Set the WHILE operator precedence
    PDAPrecedence[WhileOP][ADDOP] = '<';
    PDAPrecedence[WhileOP][SUBOP] = '<';
    PDAPrecedence[WhileOP][LeftPrenOP] = '<';
    PDAPrecedence[WhileOP][MulOP] = '<';
    PDAPrecedence[WhileOP][DivOP] = '<';
    PDAPrecedence[WhileOP][DoOP] = '=';
    PDAPrecedence[WhileOP][ODDOP] = '<';
    PDAPrecedence[WhileOP][EqualityOP] = '<';
    PDAPrecedence[WhileOP][NotEqualOP] = '<';
    PDAPrecedence[WhileOP][GreaterThanOP] = '<';
    PDAPrecedence[WhileOP][LessThanOP] = '<';
    PDAPrecedence[WhileOP][GreaterThanEqualOP] = '<';
    PDAPrecedence[WhileOP][LessThanEqualOP] = '<';


    // Set the DO operator precedence
    PDAPrecedence[DoOP][AssignOp] = '<';
    PDAPrecedence[DoOP][WhileOP] = '<';
    PDAPrecedence[DoOP][RightBraceOP] = '<';
    PDAPrecedence[DoOP][CallOP] = '<';


    // Set the ODD operator precedence
    PDAPrecedence[ODDOP][ADDOP] = '<';
    PDAPrecedence[ODDOP][SUBOP] = '<';
    PDAPrecedence[ODDOP][LeftPrenOP] = '<';
    PDAPrecedence[ODDOP][MulOP] = '<';
    PDAPrecedence[ODDOP][DivOP] = '<';
    PDAPrecedence[ODDOP][THENOP] = '>';


    // Set the Equality operator precedence
    PDAPrecedence[EqualityOP][ADDOP] = '<';
    PDAPrecedence[EqualityOP][SUBOP] = '<';
    PDAPrecedence[EqualityOP][LeftPrenOP] = '<';
    PDAPrecedence[EqualityOP][MulOP] = '<';
    PDAPrecedence[EqualityOP][DivOP] = '<';
    PDAPrecedence[EqualityOP][THENOP] = '>';


    // Set the Not Equal operator precedence
    PDAPrecedence[NotEqualOP][ADDOP] = '<';
    PDAPrecedence[NotEqualOP][SUBOP] = '<';
    PDAPrecedence[NotEqualOP][LeftPrenOP] = '<';
    PDAPrecedence[NotEqualOP][MulOP] = '<';
    PDAPrecedence[NotEqualOP][DivOP] = '<';
    PDAPrecedence[NotEqualOP][THENOP] = '>';


    // Set the Greater Than operator precedence
    PDAPrecedence[GreaterThanOP][ADDOP] = '<';
    PDAPrecedence[GreaterThanOP][SUBOP] = '<';
    PDAPrecedence[GreaterThanOP][LeftPrenOP] = '<';
    PDAPrecedence[GreaterThanOP][MulOP] = '<';
    PDAPrecedence[GreaterThanOP][DivOP] = '<';
    PDAPrecedence[GreaterThanOP][THENOP] = '>';


    // Set the Less Than operator precedence
    PDAPrecedence[LessThanOP][ADDOP] = '<';
    PDAPrecedence[LessThanOP][SUBOP] = '<';
    PDAPrecedence[LessThanOP][LeftPrenOP] = '<';
    PDAPrecedence[LessThanOP][MulOP] = '<';
    PDAPrecedence[LessThanOP][DivOP] = '<';
    PDAPrecedence[LessThanOP][THENOP] = '>';


    // Set the Greater Than Equal operator precedence
    PDAPrecedence[GreaterThanEqualOP][ADDOP] = '<';
    PDAPrecedence[GreaterThanEqualOP][SUBOP] = '<';
    PDAPrecedence[GreaterThanEqualOP][LeftPrenOP] = '<';
    PDAPrecedence[GreaterThanEqualOP][MulOP] = '<';
    PDAPrecedence[GreaterThanEqualOP][DivOP] = '<';
    PDAPrecedence[GreaterThanEqualOP][THENOP] = '>';


    // Set the Less Than Equal operator precedence
    PDAPrecedence[LessThanEqualOP][ADDOP] = '<';
    PDAPrecedence[LessThanEqualOP][SUBOP] = '<';
    PDAPrecedence[LessThanEqualOP][LeftPrenOP] = '<';
    PDAPrecedence[LessThanEqualOP][MulOP] = '<';
    PDAPrecedence[LessThanEqualOP][DivOP] = '<';
    PDAPrecedence[LessThanEqualOP][THENOP] = '>';


    // Set the Left Brace operator precedence
    PDAPrecedence[LeftBraceOP][AssignOp] = '<';
    PDAPrecedence[LeftBraceOP][IFOP] = '<';
    PDAPrecedence[LeftBraceOP][WhileOP] = '<';
    PDAPrecedence[LeftBraceOP][LeftBraceOP] = '<';
    PDAPrecedence[LeftBraceOP][RightBraceOP] = '=';
    PDAPrecedence[LeftBraceOP][CallOP] = '<';

}
ParseOps Parse::ParseMap(const Tokens &token) // Parse map
{
    if(token.lexeme == ";") return ArnoldOP; // Return the Arnold operator
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
    if(token.lexeme == "==") return EqualityOP; // Return the Equality operator
    if(token.lexeme == "!=") return NotEqualOP; // Return the Not Equal operator
    if(token.lexeme == ">") return GreaterThanOP; // Return the Greater Than operator
    if(token.lexeme == "<") return LessThanOP; // Return the Less Than operator
    if(token.lexeme == ">=") return GreaterThanEqualOP; // Return the Greater Than Equal operator
    if(token.lexeme == "<=") return LessThanEqualOP; // Return the Less Than Equal operator
    if(token.lexeme == "{") return LeftBraceOP; // Return the Left Brace operator
    if(token.lexeme == "}") return RightBraceOP; // Return the Right Brace operator
    if(token.lexeme == "CALL" || token.lexeme == "call") return CallOP; // Return the CALL operator
    return NonOP; // Return the Non operator for everything else

}












