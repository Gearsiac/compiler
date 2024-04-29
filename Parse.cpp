#include <iostream>
#include <string>
#include <iomanip>
#include "lexical.h"
#include "Parse.h"
#include "symbol.h"
#include "EnumerationTypes.h"
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
    PDAPrecedenceTable[EqualityOP][DoOP] = '>';


    // Set the Not Equal operator precedence
    PDAPrecedenceTable[NotEqualOP][ADDOP] = '<';
    PDAPrecedenceTable[NotEqualOP][SUBOP] = '<';
    PDAPrecedenceTable[NotEqualOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[NotEqualOP][MulOP] = '<';
    PDAPrecedenceTable[NotEqualOP][DivOP] = '<';
    PDAPrecedenceTable[NotEqualOP][THENOP] = '>';
    PDAPrecedenceTable[NotEqualOP][DoOP] = '>';


    // Set the Greater Than operator precedence
    PDAPrecedenceTable[GreaterThanOP][ADDOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][SUBOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][MulOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][DivOP] = '<';
    PDAPrecedenceTable[GreaterThanOP][THENOP] = '>';
    PDAPrecedenceTable[GreaterThanOP][DoOP] = '>';


    // Set the Less Than operator precedence
    PDAPrecedenceTable[LessThanOP][ADDOP] = '<';
    PDAPrecedenceTable[LessThanOP][SUBOP] = '<';
    PDAPrecedenceTable[LessThanOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[LessThanOP][MulOP] = '<';
    PDAPrecedenceTable[LessThanOP][DivOP] = '<';
    PDAPrecedenceTable[LessThanOP][THENOP] = '>';
    PDAPrecedenceTable[LessThanOP][DoOP] = '>';


    // Set the Greater Than Equal operator precedence
    PDAPrecedenceTable[GreaterThanEqualOP][ADDOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][SUBOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][MulOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][DivOP] = '<';
    PDAPrecedenceTable[GreaterThanEqualOP][THENOP] = '>';
    PDAPrecedenceTable[GreaterThanEqualOP][DoOP] = '>';


    // Set the Less Than Equal operator precedence
    PDAPrecedenceTable[LessThanEqualOP][ADDOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][SUBOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][LeftPrenOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][MulOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][DivOP] = '<';
    PDAPrecedenceTable[LessThanEqualOP][THENOP] = '>';
    PDAPrecedenceTable[LessThanEqualOP][DoOP] = '>';


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
    
    PDAConfig(); // Configure the PDA
    
}
void Parse :: ProcessPrens() // Handle the closing parenthesis
{
    if(StackCount > 1) // If the stack count is greater than 1
    {
        if(ParseStack[StackCount - 1]->lexeme == ")" && ParseStack[StackCount - 3]->lexeme == "(") // If the top of the stack is a right parenthesis and the second top is a left parenthesis
        {
            ParseStack[StackCount -3] = ParseStack[StackCount - 2]; // Pop the parenthesis pair
            StackCount -= 2; // Pop the parenthesis pair
        }
    }
}
void Parse :: ProcessBraces() // Handle the closing braces
{
    
    if(StackCount >= 4)
    {
        
        if (ParseStack[StackCount -1]->lexeme == "}" && ParseStack[StackCount - 2]->lexeme == "{")
        {
            StackCount -= 2;
        }
        else if(ParseStack[StackCount - 1]->lexeme == "}" && ParseStack[StackCount - 3]-> lexeme == "{")
        {
            ParseStack[StackCount - 3] = ParseStack[StackCount - 2];
            StackCount -= 2;
        }
        
    }
}
void Parse :: ProcessThen() // Handle the THEN
{
    Quads GetLast = ParseQuads[QuadsCount - 1];
    string Instruction;
    string Label = "L" + to_string(LabelCount++);
    if(GetLast.op == ">")
        Instruction = "JLE";
    if(GetLast.op == "<")
        Instruction = "JGE";
    if(GetLast.op == ">=")
        Instruction = "JL";
    if(GetLast.op == "<=")
        Instruction = "JG";
    if(GetLast.op == "==")
        Instruction = "JNE";
    if(GetLast.op == "!=")
        Instruction = "JE";
    AddToQuads("THEN", Label, Instruction, "?");
    AddTofixer(Label);
}
void Parse :: ProcessElse() // Handle the IF ELSE
{
    string Label = "L" + to_string(LabelCount++);
    string FixerLabel = FixerUpper[FixerCount - 1];
    AddToQuads("ELSE", Label, "?", "?");
    AddToEndOfStack(Label);
    FixerCount -= 1;
    AddToQuads("J", FixerLabel, "?", "?");

}
void Parse :: ReduceIfThen() // Pop the IF THEN
{
    string Label = FixerUpper[FixerCount - 1];
    if(StackCount > 1)
    {
        if(ParseStack[StackCount - 1]->lexeme == "THEN" && ParseStack[StackCount - 2]->lexeme == "IF")
        {
            StackCount -= 2;
            FixerCount -= 1;
            AddToQuads("J", Label, "?", "?");
        }
    }
}
void Parse :: ReduceIfThenElse() // Pop the IF THEN ELSE
{
    string Label = EndOfStack[EndOfStackCount - 1];
    if(StackCount > 1)
    {
        if(ParseStack[StackCount - 1]->lexeme == "ELSE" && ParseStack[StackCount - 2]->lexeme == "THEN" && ParseStack[StackCount - 3]->lexeme == "IF")
        {
            StackCount -= 3;
            EndOfStackCount -= 1;
            AddToQuads("J", Label, "?", "?");

        }
    }
}
void Parse :: ProcessIF() // Handle the IF
{    
    AddToQuads("IF", "?", "?", "?"); // Add to the quads

}
void Parse :: ProcessWhile() // Handle the WHILE
{
    string WhileStart = "W" + to_string(WhileLabelCount++);
    AddToQuads("WHILE", WhileStart, "?", "?");
    AddToWhileStack(WhileStart);
    
}
void Parse :: ProcessDo() // Handle the DO
{
    Quads GetLast = ParseQuads[QuadsCount - 1];
    string Instruction;
    string Label = "L" + to_string(LabelCount++);
    if(GetLast.op == ">")
        Instruction = "JLE";
    if(GetLast.op == "<")
        Instruction = "JGE";
    if(GetLast.op == ">=")
        Instruction = "JL";
    if(GetLast.op == "<=")
        Instruction = "JG";
    if(GetLast.op == "==")
        Instruction = "JNE";
    if(GetLast.op == "!=")
        Instruction = "JE";
    AddToQuads("DO", Label, Instruction, "?");
    AddToEndOfStack(Label);
}
void Parse :: EndOfParseHandling()
{
    if(ParseStack[StackCount - 1]->lexeme == "EOF" && ParseStack[StackCount - 2]->lexeme == "}" && ParseStack[StackCount - 3]->lexeme == "{" )
    {
        StackCount -= 3;
    }
}
void Parse :: ReduceAritmatic() // Handle the aritmatic
{
                string arg1, arg2, op, Temp;
                arg2 = (*ParseStack[StackCount - 1]).lexeme; // First argument right below the top
                op = (*ParseStack[StackCount - 2]).lexeme;  // Operator
                arg1 = (*ParseStack[StackCount - 3]).lexeme; // Second argument below the operator
                StackCount -= 3; // Reduce the stack
                if(op == "+"|| op == "-" || op == "*" || op == "/")
                {
                    Temp = "T" + to_string(TempCount++); // Get the new Temp
                    AddToQuads(op, arg1, arg2, Temp); // Add to the quads
                    ParseStack[StackCount++] = new Tokens(Temp, " "); // Add to the stack
                    
                }
                else
                {   
                    AddToQuads(op, arg1, arg2, " ? "); // Add to the quads
                }
}
void Parse :: ReduceWhileAndDo() // Pop the WHILE DO
{
    string Label = EndOfStack[EndOfStackCount - 1];
    string While = WhileStack[WhileCount - 1];
    if(ParseStack[StackCount - 1]->lexeme == "DO" && ParseStack[StackCount - 2]->lexeme == "WHILE")
    {
            StackCount -= 2;
    }
    WhileCount -= 1;
    AddToQuads("JMP", While, "?", "?");
    EndOfStackCount-=1;
    AddToQuads("J", Label, "?", "?");
}
char Parse :: ReadRowsAndCollums(ParseOps currentState, ParseOps input) // Read the rows and collums
{
    return PDAPrecedenceTable[currentState][input]; // Return the rows and collums
}
int Parse :: getQuadsCount() const // Get the Parse quads count
{
    return QuadsCount; // Return the Parse quads count
}
void Parse :: AddToEndOfStack(string Label) // Add to the End of stack
{
    EndOfStack[EndOfStackCount++] = Label; // Add to the End of stack
}
Quads* Parse :: getParseQuads() // Get the Parse quads
{
    return ParseQuads; // Return the Parse quads
}
ParseOps Parse::GetTopOperator() // Pop and lock the top OP that drop
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
    ParseQuads[QuadsCount++] = Quads(op, arg1, arg2, Temp); // Add to the Parse quads
}
void Parse :: AddToWhileStack(string WhileLabel) // Add to the While stack
{
    WhileStack[WhileCount++] = WhileLabel; // Add to the While stack
}
void Parse :: AddTofixer(string Label) // Add to the Fixer
{
   FixerUpper[FixerCount++] = Label; // Add to the Fixer
}
void Parse::PDAParseing(const Tokens& token, Tokens* tokens, int tokenCount) // Stack handling 
{
    Tokens CurrentToken, TopToken;
    ParseOps CurrentOPS, TopOPSDrops;
    ParseStack[StackCount++] = new Tokens(";", "T-101");
    string op, arg1, arg2, Temp, Label;
    for(int i = 0; i < tokenCount; i++) // Loop through the tokens
    {
        CurrentToken = tokens[i]; // Get the token
        CurrentOPS = ParseMap(CurrentToken); // Get the input
        if(CurrentToken.lexeme == "CLASS")
        {
            while(tokens[i].lexeme != "{")
            {
                 i++;
            }
            ParseStack[StackCount++] = new Tokens(tokens[i].lexeme, tokens[i].tokenType);
            continue;
        }
        if(CurrentToken.lexeme == "CONST" || CurrentToken.lexeme == "VAR")
        {
            while(tokens[i].lexeme != ";")
            {
                i++;
            }
            continue;
        }
        if(CurrentToken.lexeme == "CIN" || CurrentToken.lexeme == "COUT")
        {
            while(tokens[i].lexeme != ";")
            {
                if(tokens[++i].tokenType == "Variable")
                {
                AddToQuads(CurrentToken.lexeme, tokens[i].lexeme, "?", "?");
                }
            }
            continue;
        }
        if(CurrentOPS == NonOP) 
        {
            ParseStack[StackCount++] = new Tokens(CurrentToken.lexeme, CurrentToken.tokenType);
            TopToken  = *ParseStack[StackCount - 1];
        }
        TopOPSDrops = GetTopOperator(); // Get the top operator
        char Relation = ReadRowsAndCollums(TopOPSDrops, CurrentOPS); // Get the precedence
        if((Relation == '<' || Relation == '='|| Relation == '?' ) && CurrentOPS != NonOP)
        {
            ParseStack[StackCount++] = new Tokens(CurrentToken.lexeme, CurrentToken.tokenType);
            TopToken = *ParseStack[StackCount - 1];
        }
        if (Relation == '>') 
        {
            bool reduce = true;
            while (reduce) 
            {
                ReduceAritmatic(); // Handle the aritmatic
                TopOPSDrops = GetTopOperator(); // Get the top operator
                Relation = ReadRowsAndCollums(TopOPSDrops, CurrentOPS); // Get the precedence
                if(Relation == '<' ||Relation == '=' || Relation == '?')
                {
                    reduce = false;
                  
                    if(CurrentToken.lexeme != ";")
                    {
                       ParseStack[StackCount++] = new Tokens(CurrentToken.lexeme, CurrentToken.tokenType);
                        break;
                    }
                    break;
                }   
            }
        }
        if(CurrentToken.lexeme == "}")
        {
            ProcessBraces();
        }
        if(CurrentToken.lexeme == ")")
        {
            ProcessPrens();
        }
        if(CurrentToken.lexeme == "IF")
        {
            ProcessIF();
        }
        if(CurrentToken.lexeme == "THEN")
        {
            ProcessThen(); 
        }
        if(CurrentToken.lexeme == "ELSE")
        {
            ProcessElse();
        }
        if((CurrentToken.lexeme == "}" || CurrentToken.lexeme == ";") && (ParseStack[StackCount - 1]->lexeme == "THEN") && ((i + 1 < tokenCount) && (tokens[i + 1].lexeme != "ELSE")))
        {
            ReduceIfThen();
        }
        if((CurrentToken.lexeme == "}" || CurrentToken.lexeme == ";") && ParseStack[StackCount - 2]->lexeme == "THEN" && ParseStack[StackCount - 1]->lexeme == "ELSE")
        {
            ReduceIfThenElse();
        }
        if(CurrentToken.lexeme == "WHILE")
        {
            ProcessWhile();
        }
        if(CurrentToken.lexeme == "DO")
        {
            ProcessDo();
        }
        if((CurrentToken.lexeme == "}" || CurrentToken.lexeme == ";") && ParseStack[StackCount -1]->lexeme == "DO" && ((i + 1 < tokenCount) && (tokens[i + 1].lexeme != "WHILE"))){
            ReduceWhileAndDo();
        }
        if(CurrentToken.lexeme == "EOF")
        {
            EndOfParseHandling();
        } 
    }
}



