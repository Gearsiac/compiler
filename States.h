#ifndef STATES_H
#define STATES_H
#include <string>
#include <vector>
#include <iostream>
#include <string>
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
    lessThanEqualsStateFinal,
    greaterThanState,
    greaterThanFinal,
    greaterThanEqualsStateFinal,
    exclemationState,
    NotstateFinal,
    notEqualsStateFinal,
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
    equals,
    lessThan,
    greaterThan,
    exlimation,
    leftparen,
    rightparen,
    leftbrace,
    rightbrace,
    comma,
    semicolon,
    WS,
    other,
    typeCount
};
enum symbolstates
{
    StartState,
    ClassState,
    PrgmState,
    LBState,
    constState, 
    VState,
    AssState,
    integer_State,
    VarState,
    VariState,
    keyState,
    literalState,
    EOFState,
    SymStateCount
};
enum symbolTypes
{
    ClassType,
    variableType,
    LBType,
    constIdentifierType,
    AssType,
    int_Type,
    semitype,
    commaType,
    VarIdentifierType,
    keyType,
    EOFtype,
    otherType,
    SymTypeCount

};
#endif