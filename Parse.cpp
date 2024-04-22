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
void Parse :: LabelGenerator(string Label) // Label generator
{
    Label = "L" + to_string(LabelCount++); // Get the Label
}
void Parse :: WhileGenerator(string While) // While generator
{
    While = "W" + to_string(WhileCount++); // Get the While
}
void Parse :: AddToFixerUpper(const string fixer) // Add to the fixer upper
{
    FixerUpper[FixerCount++] = stoi(fixer); // Add to the fixer upper
}
void Parse :: AddToWhileStack(const string While) // Add to the while stack
{
    WhileStack[WhileCount++] = stoi(While); // Add to the while stack
}
void Parse :: HandleClosingPrens(const Tokens& tokens ) // Handle the closing parenthesis
{
    
    
}
void Parse :: HandleClosingBraces() // Handle the closing braces
{
    
}
void Parse :: HandleIF() // Handle the IF
{
    cout << "Handling IF" << endl;
}
void Parse :: HandleThen() // Handle the THEN
{
    cout << "Handling THEN" << endl;
}
void Parse :: HandleIfElse() // Handle the IF ELSE
{
    cout << "Handling IF ELSE" << endl;
}
void Parse :: PopIFTHEN() // Pop the IF THEN
{
    cout << "Popping IF THEN" << endl;
}
void Parse :: PopIfThenElse() // Pop the IF THEN ELSE
{
    cout << "Popping IF THEN ELSE" << endl;
}
void Parse :: HandleWhile() // Handle the WHILE
{
    cout << "Handling WHILE" << endl;
}
void Parse :: HandleDo() // Handle the DO
{
    cout << "Handling DO" << endl;
}
void Parse :: PopWhileDo() // Pop the WHILE DO
{
    cout << "Popping WHILE DO" << endl;
}
char Parse :: ReadRowsAndCollums(ParseOps currentState, ParseOps input) // Read the rows and collums
{
    return PDAPrecedenceTable[currentState][input]; // Return the rows and collums
}
int Parse :: getQuadsCount() const // Get the Parse quads count
{
    return QuadsCount; // Return the Parse quads count
}
Quads* Parse :: getParseQuads() // Get the Parse quads
{
    return *ParseQuads; // Return the Parse quads
}

ParseOps Parse::PopAndLockTheTopOPThatDrop() // Pop and lock the top OP that drop
{
    Tokens TopToken;
    ParseOps TopOPSDrops;
    for(int i = StackCount - 1; i >= 0; i--) // Loop through the stack
    {
        TopToken = *ParseStack[i]; // Get the top token
        TopOPSDrops = ParseMap(TopToken); // Get the top input
        if(TopOPSDrops != NonOP) // If the top drops
        {
            break; // Break
        }    
    }
    return TopOPSDrops; // Return the top drops
}
void Parse :: AddToQuads(const string& op, const string& arg1, const string& arg2, const string& Temp) // Add to the Parse quads
{
    ParseQuads[QuadsCount++] = new Quads(op, arg1, arg2, Temp); // Add to the Parse quads    
}

void Parse::Parseing(const Tokens& token, Tokens* tokens, int tokenCount) // Stack handling 
{
    Tokens CurrentToken, TopToken;
    ParseOps CurrentOPS, TopOPSDrops;
    ParseStack[StackCount++] = new Tokens(";", "T-101");
    cout << "Top token is " << TopToken.lexeme << endl;
    string op, arg1, arg2, Temp;
    for(int i = 0; i < tokenCount; i++) // Loop through the tokens
    {
        CurrentToken = tokens[i]; // Get the token
        CurrentOPS = ParseMap(CurrentToken); // Get the input
        cout << "Processing token " << CurrentToken.lexeme << endl;
        if(CurrentToken.lexeme == "CLASS")
        {
            while(tokens[i].lexeme != "{")
            {
                 i++;
                cout << "skipping" << tokens[i].lexeme << endl;
            }
            continue;
        }
        if(CurrentToken.lexeme == "CONST" || CurrentToken.lexeme == "VAR")
        {
            while(tokens[i].lexeme != ";")
            {
                i++;
                cout << "skipping" << tokens[i].lexeme << endl;
            }
            continue;
        }
        if(CurrentOPS == NonOP) // Fix: Replace CurrentOps with CurrentOPS
        {
            cout << "Pushing " << CurrentToken.lexeme << endl;
            cout << "Current token is " << CurrentToken.lexeme << endl;
             cout << "Top token is " << TopToken.lexeme << endl;
            ParseStack[StackCount++] = new Tokens(CurrentToken.lexeme, CurrentToken.tokenType);
            TopToken  = *ParseStack[StackCount - 1];
            cout << " Stack :" << endl;
                for(int i = 0; i < StackCount; i++)
                {
                    cout << ParseStack[i]->lexeme << " ";
                }
        }
        TopOPSDrops = PopAndLockTheTopOPThatDrop(); // Get the top operator
        char Relation = ReadRowsAndCollums(TopOPSDrops, CurrentOPS); // Get the precedence
        cout << "Relation is " << Relation << endl;
        if(Relation == '<' || Relation == '=')
        {
            ParseStack[StackCount++] = new Tokens(CurrentToken.lexeme, CurrentToken.tokenType);
            TopToken = *ParseStack[StackCount - 1];
            cout << "Pushing " << CurrentToken.lexeme << endl;
            cout << "Current token is " << CurrentToken.lexeme << endl;
            cout << "Top token is " << TopToken.lexeme << endl;
            cout << " Stack :" << endl;
                for(int i = 0; i < StackCount; i++)
                {
                    cout << ParseStack[i]->lexeme << " ";
                }
        }
        if (Relation == '>') 
        {
            
            bool reduce = true;
            while (reduce) 
            {
                // Access elements for potential reduction
                arg1 = (*ParseStack[StackCount - 1]).lexeme; // First argument right below the top
                op = (*ParseStack[StackCount - 2]).lexeme;  // Operator
                arg2 = (*ParseStack[StackCount - 3]).lexeme; // Second argument below the operator
                StackCount -= 3; // Reduce the stack
                if(op == "+"|| op == "-" || op == "*" || op == "/")
                {
                    AddToQuads(op, arg1, arg2, Temp); // Add to the quads
                    Temp = "T" + to_string(TempCount++); // Get the new Temp
                    ParseStack[StackCount++] = new Tokens(Temp, " "); // Add to the stack

                    cout << "Currently reducing: " << op << " " << arg2 << " " << arg1 << " " << Temp << " "<< endl;
                }
                else
                {   
                    AddToQuads(op, arg2, Temp, "?"); // Add to the quads
                    cout << "Currently reducing: " << op << " " << arg2 << " " << Temp << " " << "?" << endl;
                    

                }
                cout << "Reduced stack count: " << StackCount << endl;
                TopOPSDrops = PopAndLockTheTopOPThatDrop(); // Get the top operator
                Relation = ReadRowsAndCollums(TopOPSDrops, CurrentOPS); // Get the precedence
                if(Relation == '<' ||Relation == '=' || Relation == '?')
                {
                    reduce = false;
                  
                    if(CurrentToken.lexeme != ";")
                    {
                       ParseStack[StackCount++] = new Tokens(CurrentToken.lexeme, CurrentToken.tokenType);
                       cout << "Pushing " << CurrentToken.lexeme << endl;
                        break;
                    }
                    break;
                }

                
            }
        }
        
    }
}


