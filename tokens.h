#ifndef TOKENS_H
#define TOKENS_H
#include <iostream>
using namespace std;

enum state
{
    start,
    error,
    operatorState,
    digitState,
    digitFinal,
    identifierState,
    identifierFinal,
    slashState,
    DivisorFinal,
    commentState,
    commentFinal,
    equalsState,
    assignmentFinal,
    lessThanState,
    lessThanFinal,
    lessThanEqualsState,
    greaterThanState,
    greaterThanFinal,
    greaterThanEqualsState,
    exclemationState,
    notEqualsState,
    delimiterState,
    braceState,
    parenState,
    StateCount
};
enum types
{
    letter,
    digit,
    astrix,
    plusType,
    minusType,
    slash,
    newline,
    wsType,
    equals,
    lessThan,
    greaterThan,
    comma,
    semicolon,
    exlimation,
    leftBrace,
    rightBrace,
    leftParen,
    rightParen,
    other,
    typeCount
};
enum ReservedWords
{
    ConstType,
    procedure,
    odd,
    ifType,
    whileType,
    classType,
    var,
    call,
    then,
    doType
};
int Table[StateCount][typeCount] = {};
void StratingTable() {
Table[start][letter] = identifierState;
Table[start][digit] = digitState;
Table[start][astrix] = operatorState;
Table[start][plusType] = operatorState;
Table[start][minusType] = operatorState;
Table[start][slash] = slashState;
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
Table[start][other] = error;
}
#endif