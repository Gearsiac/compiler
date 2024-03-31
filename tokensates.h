#ifndef TOKENS_H
#define TOKENS_H
#include <iostream>
using namespace std;

enum state
{
    start,
    error,
    operation,
    digitState,
    integerFinal,
    VariableState,
    VariableFinal,
    slashState,
    commentState,
    commentFinal,
    DivisorFinal,
    equalsState,
    assignmentFinal,
    equalityFinal,
    lessThanState,
    lessThanFinal,
    lessThanEqualsState,
    greaterThanState,
    greaterThanFinal,
    greaterThanEqualsState,
    exclemationState,
    NotstateFinal,
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
    divisor,
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
#endif