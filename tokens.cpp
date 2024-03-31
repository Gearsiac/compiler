#include <iostream>
#include <string>
#include "tokens.h"
int Table[StateCount][typeCount] = {0};
using namespace std;
class TokenFSA
{

public:
static int initilizeTable();
static int initilizeTable()
{

    // 2D array of states and types
Table[start][letter] = VariableState;
Table[start][digit] = digitState;
Table[start][astrix] = operation;
Table[start][plusType] = operation;
Table[start][minusType] = operation;
Table[start][divisor] = slashState;
Table[start][newline] = start;
Table[start][wsType] = start;
Table[start][equals] = equalsState;
Table[start][lessThan] = lessThanState;
Table[start][greaterThan] = greaterThanState;
Table[start][comma] = delimiterState;
Table[start][semicolon] = delimiterState;
Table[start][exlimation] = exclemationState;
Table[start][leftBrace] = braceState;
Table[start][rightBrace] = braceState;
Table[start][leftParen] = parenState;
Table[start][rightParen] = parenState;
//Error state
Table[start][other] = error;
Table[error][letter] = error;
Table[error][digit] = error;
Table[error][astrix] = error;
Table[error][plusType] = error;
Table[error][minusType] = error;
Table[error][divisor] = error;
Table[error][newline] = error;
Table[error][wsType] = error;
Table[error][equals] = error;
Table[error][lessThan] = error;
Table[error][greaterThan] = error;
Table[error][comma] = error;
Table[error][semicolon] = error;
Table[error][exlimation] = error;
Table[error][leftBrace] = error;
Table[error][rightBrace] = error;
Table[error][leftParen] = error;
Table[error][rightParen] = error;

//digit state
Table[digitState][letter] = integerFinal;
Table[digitState][digit] = digitState;
Table[digitState][astrix] = integerFinal;
Table[digitState][plusType] = integerFinal;
Table[digitState][minusType] = integerFinal;
Table[digitState][divisor] = integerFinal;
Table[digitState][newline] = integerFinal;
Table[digitState][wsType] = integerFinal;
Table[digitState][equals] = integerFinal;
Table[digitState][lessThan] = integerFinal;
Table[digitState][greaterThan] = integerFinal;
Table[digitState][comma] = integerFinal;
Table[digitState][semicolon] = integerFinal;
Table[digitState][exlimation] = integerFinal;
Table[digitState][leftBrace] = integerFinal;
Table[digitState][rightBrace] = integerFinal;
Table[digitState][leftParen] = integerFinal;
Table[digitState][rightParen] = integerFinal;

//Variable state
Table[VariableState][letter] = VariableState;
Table[VariableState][digit] = VariableState;
Table[VariableState][astrix] = VariableFinal;
Table[VariableState][plusType] = VariableFinal;
Table[VariableState][minusType] = VariableFinal;
Table[VariableState][divisor] = VariableFinal;
Table[VariableState][newline] = VariableFinal;
Table[VariableState][wsType] = VariableFinal;
Table[VariableState][equals] = VariableFinal;
Table[VariableState][lessThan] = VariableFinal;
Table[VariableState][greaterThan] = VariableFinal;
Table[VariableState][comma] = VariableFinal;
Table[VariableState][semicolon] = VariableFinal;
Table[VariableState][exlimation] = VariableFinal;
Table[VariableState][leftBrace] = VariableFinal;
Table[VariableState][rightBrace] = VariableFinal;
Table[VariableState][leftParen] = VariableFinal;
Table[VariableState][rightParen] = VariableFinal;

//slash state
Table[slashState][divisor] = DivisorFinal;
Table[slashState][astrix] = commentState;
Table[commentState][digit] = commentState;
Table[commentState][letter] = commentState;
Table[commentState][plusType] = commentState;
Table[commentState][minusType] = commentState;
Table[commentState][newline] = commentState;
Table[commentState][wsType] = commentState;
Table[commentState][equals] = commentState;
Table[commentState][lessThan] = commentState;
Table[commentState][greaterThan] = commentState;
Table[commentState][comma] = commentState;
Table[commentState][semicolon] = commentState;
Table[commentState][exlimation] = commentState;
Table[commentState][leftBrace] = commentState;
Table[commentState][rightBrace] = commentState;
Table[commentState][leftParen] = commentState;
Table[commentState][rightParen] = commentState;
Table[commentState][astrix] = commentFinal;
Table[commentFinal][letter] = commentState;
Table[commentFinal][digit] = commentState;
Table[commentFinal][plusType] = commentState;
Table[commentFinal][minusType] = commentState;
Table[commentFinal][newline] = commentState;
Table[commentFinal][wsType] = commentState;
Table[commentFinal][equals] = commentState;
Table[commentFinal][lessThan] = commentState;
Table[commentFinal][greaterThan] = commentState;
Table[commentFinal][comma] = commentState;
Table[commentFinal][semicolon] = commentState;
Table[commentFinal][exlimation] = commentState;
Table[commentFinal][leftBrace] = commentState;
Table[commentFinal][rightBrace] = commentState;
Table[commentFinal][leftParen] = commentState;
Table[commentFinal][rightParen] = commentState;
Table[commentFinal][divisor] = start;

//equals state
Table[equalsState][letter] = assignmentFinal;
Table[equalsState][digit] = assignmentFinal;
Table[equalsState][astrix] = assignmentFinal;
Table[equalsState][plusType] = assignmentFinal;
Table[equalsState][minusType] = assignmentFinal;
Table[equalsState][divisor] = assignmentFinal;
Table[equalsState][newline] = assignmentFinal;
Table[equalsState][wsType] = assignmentFinal;
Table[equalsState][equals] = equalityFinal;
Table[equalsState][lessThan] = assignmentFinal;
Table[equalsState][greaterThan] = assignmentFinal;
Table[equalsState][comma] = assignmentFinal;
Table[equalsState][semicolon] = assignmentFinal;
Table[equalsState][leftBrace] = assignmentFinal;
Table[equalsState][rightBrace] = assignmentFinal;
Table[equalsState][leftParen] = assignmentFinal;
Table[equalsState][rightParen] = assignmentFinal;
//less than state
Table[lessThanState][letter] = lessThanFinal;
Table[lessThanState][digit] = lessThanFinal;
Table[lessThanState][astrix] = lessThanFinal;
Table[lessThanState][plusType] = lessThanFinal;
Table[lessThanState][minusType] = lessThanFinal;
Table[lessThanState][divisor] = lessThanFinal;
Table[lessThanState][newline] = lessThanFinal;
Table[lessThanState][wsType] = lessThanFinal;
Table[lessThanState][equals] = lessThanEqualsState;
Table[lessThanState][lessThan] = lessThanFinal;
Table[lessThanState][greaterThan] = lessThanFinal;
Table[lessThanState][comma] = lessThanFinal;
Table[lessThanState][semicolon] = lessThanFinal;
Table[lessThanState][leftBrace] = lessThanFinal;
Table[lessThanState][rightBrace] = lessThanFinal;
Table[lessThanState][leftParen] = lessThanFinal;
Table[lessThanState][rightParen] = lessThanFinal;
//greater than state
Table[greaterThanState][letter] = greaterThanFinal;
Table[greaterThanState][digit] = greaterThanFinal;
Table[greaterThanState][astrix] = greaterThanFinal;
Table[greaterThanState][plusType] = greaterThanFinal;
Table[greaterThanState][minusType] = greaterThanFinal;
Table[greaterThanState][divisor] = greaterThanFinal;
Table[greaterThanState][newline] = greaterThanFinal;
Table[greaterThanState][wsType] = greaterThanFinal;
Table[greaterThanState][equals] = greaterThanEqualsState;
Table[greaterThanState][lessThan] = greaterThanFinal;
Table[greaterThanState][greaterThan] = greaterThanFinal;
Table[greaterThanState][comma] = greaterThanFinal;
Table[greaterThanState][semicolon] = greaterThanFinal;
Table[greaterThanState][leftBrace] = greaterThanFinal;
Table[greaterThanState][rightBrace] = greaterThanFinal;
Table[greaterThanState][leftParen] = greaterThanFinal;
Table[greaterThanState][rightParen] = greaterThanFinal;
//exclemation state
Table[exclemationState][letter] = NotstateFinal;
Table[exclemationState][digit] = NotstateFinal;
Table[exclemationState][astrix] = NotstateFinal;
Table[exclemationState][plusType] = NotstateFinal;
Table[exclemationState][minusType] = NotstateFinal;
Table[exclemationState][divisor] = NotstateFinal;
Table[exclemationState][newline] = NotstateFinal;
Table[exclemationState][wsType] = NotstateFinal;
Table[exclemationState][equals] = notEqualsState;
Table[exclemationState][lessThan] = NotstateFinal;
Table[exclemationState][greaterThan] = NotstateFinal;
Table[exclemationState][comma] = NotstateFinal;
Table[exclemationState][semicolon] = NotstateFinal;
Table[exclemationState][leftBrace] = NotstateFinal;
Table[exclemationState][rightBrace] = NotstateFinal;
Table[exclemationState][leftParen] = NotstateFinal;
Table[exclemationState][rightParen] = NotstateFinal;
return 0;
}
 
};
int main()
{
    TokenFSA::initilizeTable();
    return 0;
}

