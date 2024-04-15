#ifndef STATES_H
#define STATES_H
#include <string>
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

enum ParseStates
{
    ArnoldState,
    Assign_State,
    Add_State,
    Sub_state,
    LeftPren_State,
    RightPren_State,
    Mul_State,
    Div_State,
    IF_State,
    Else_State,
    While_State,
    Do_State,
    ODD_State,
    Equality_State,
    NotEqual_State,
    GreaterThan_State,
    LessThan_State,
    GreaterThanEqual_State,
    LessThanEqual_State,
    RightBrace_State,
    LeftBrace_State,
    Call_State,
    ParseCount
};
#endif