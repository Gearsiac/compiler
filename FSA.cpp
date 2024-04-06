#include "FSA.h"
#include "States.h"
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <iterator>
#include <regex>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "lexical.h"
using namespace std;

FSA::FSA()
{
    FSAConfig();
}
state FSA ::nextState(state currentState, types input)
{
    int next = Table[currentState][input];
    return static_cast<state>(next);
}
void FSA::FSAConfig()
{

    // 2D array of states and types
Table[start][letter] = VariableState;
Table[start][digit] = digitState;
Table[start][astrix] = operation;
Table[start][plusType] = operation;
Table[start][minusType] = operation;
Table[start][divisor] = slashState;
Table[start][equals] = equalsState;
Table[start][lessThan] = lessThanState;
Table[start][greaterThan] = greaterThanState;
Table[start][exlimation] = exclemationState;
Table[start][leftparen] = parenState;
Table[start][rightparen] = parenState;
Table[start][leftbrace] = braceState;
Table[start][rightbrace] = braceState;
Table[start][comma] = delimiterState;
Table[start][semicolon] = delimiterState;
Table[start][WS] = start;
Table[start][other] = error;




//digit state
Table[digitState][letter] = integerFinal;
Table[digitState][digit] = digitState;
Table[digitState][astrix] = integerFinal;
Table[digitState][plusType] = integerFinal;
Table[digitState][minusType] = integerFinal;
Table[digitState][divisor] = integerFinal;
Table[digitState][equals] = integerFinal;
Table[digitState][lessThan] = integerFinal;
Table[digitState][greaterThan] = integerFinal;
Table[digitState][exlimation] = integerFinal;
Table[digitState][leftparen] = integerFinal;
Table[digitState][rightparen] = integerFinal;
Table[digitState][leftbrace] = integerFinal;
Table[digitState][rightbrace] = integerFinal;
Table[digitState][comma] = integerFinal;
Table[digitState][semicolon] = integerFinal;
Table[digitState][WS] = integerFinal;
Table[digitState][other] = error;


//Variable state
Table[VariableState][letter] = VariableState;
Table[VariableState][digit] = VariableState;
Table[VariableState][astrix] = VariableFinal;
Table[VariableState][plusType] = VariableFinal;
Table[VariableState][minusType] = VariableFinal;
Table[VariableState][divisor] = VariableFinal;
Table[VariableState][equals] = VariableFinal;
Table[VariableState][lessThan] = VariableFinal;
Table[VariableState][greaterThan] = VariableFinal;
Table[VariableState][exlimation] = VariableFinal;
Table[VariableState][leftparen] = VariableFinal;
Table[VariableState][rightparen] = VariableFinal;
Table[VariableState][leftbrace] = VariableFinal;
Table[VariableState][rightbrace] = VariableFinal;
Table[VariableState][comma] = VariableFinal;
Table[VariableState][semicolon] = VariableFinal;
Table[VariableState][WS] = VariableFinal;
Table[VariableState][other] = error;


//slash state
Table[slashState][letter] = DivisorFinal;
Table[slashState][digit] = DivisorFinal;
Table[slashState][astrix] = commentState;
Table[slashState][plusType] = DivisorFinal;
Table[slashState][minusType] = DivisorFinal;
Table[slashState][divisor] = DivisorFinal;
Table[slashState][equals] = DivisorFinal;
Table[slashState][lessThan] = DivisorFinal;
Table[slashState][greaterThan] = DivisorFinal;
Table[slashState][exlimation] = DivisorFinal;
Table[slashState][leftparen] = DivisorFinal;
Table[slashState][rightparen] = DivisorFinal;
Table[slashState][leftbrace] = DivisorFinal;
Table[slashState][rightbrace] = DivisorFinal;
Table[slashState][comma] = DivisorFinal;
Table[slashState][semicolon] = DivisorFinal;
Table[slashState][WS] = DivisorFinal;
Table[slashState][other] = error;

//comment state
Table[commentState][letter] = commentState;
Table[commentState][digit] = commentState;
Table[commentState][astrix] = commentFinal;
Table[commentState][plusType] = commentState;
Table[commentState][minusType] = commentState;
Table[commentState][divisor] = commentState;
Table[commentState][equals] = commentState;
Table[commentState][lessThan] = commentState;
Table[commentState][greaterThan] = commentState;
Table[commentState][exlimation] = commentState;
Table[commentState][leftparen] = commentState;
Table[commentState][rightparen] = commentState;
Table[commentState][leftbrace] = commentState;
Table[commentState][rightbrace] = commentState;
Table[commentState][comma] = commentState;
Table[commentState][semicolon] = commentState;
Table[commentState][WS] = commentState;

Table[commentFinal][letter] = commentState;
Table[commentFinal][digit] = commentState;
Table[commentFinal][astrix] = commentState;
Table[commentFinal][plusType] = commentState;
Table[commentFinal][minusType] = commentState;
Table[commentFinal][divisor] = start;
Table[commentFinal][equals] = commentState;
Table[commentFinal][lessThan] = commentState;
Table[commentFinal][greaterThan] = commentState;
Table[commentFinal][exlimation] = commentState;
Table[commentFinal][leftparen] = commentState;
Table[commentFinal][rightparen] = commentState;
Table[commentFinal][leftbrace] = commentState;
Table[commentFinal][rightbrace] = commentState;
Table[commentFinal][comma] = commentState;
Table[commentFinal][semicolon] = commentState;
Table[commentFinal][WS] = commentState;

//equals state
Table[equalsState][letter] = assignmentFinal;
Table[equalsState][digit] = assignmentFinal;
Table[equalsState][astrix] = assignmentFinal;
Table[equalsState][plusType] = assignmentFinal;
Table[equalsState][minusType] = assignmentFinal;
Table[equalsState][divisor] = assignmentFinal;
Table[equalsState][equals] = equalityFinal;
Table[equalsState][lessThan] = assignmentFinal;
Table[equalsState][greaterThan] = assignmentFinal;
Table[equalsState][exlimation] = assignmentFinal;
Table[equalsState][leftparen] = assignmentFinal;
Table[equalsState][rightparen] = assignmentFinal;
Table[equalsState][leftbrace] = assignmentFinal;
Table[equalsState][rightbrace] = assignmentFinal;
Table[equalsState][comma] = assignmentFinal;
Table[equalsState][semicolon] = assignmentFinal;
Table[equalsState][WS] = assignmentFinal;
Table[equalsState][other] = error;



//less than state
Table[lessThanState][letter] = lessThanFinal;
Table[lessThanState][digit] = lessThanFinal;
Table[lessThanState][astrix] = lessThanFinal;
Table[lessThanState][plusType] = lessThanFinal;
Table[lessThanState][minusType] = lessThanFinal;
Table[lessThanState][divisor] = lessThanFinal;
Table[lessThanState][equals] = lessThanEqualsStateFinal;
Table[lessThanState][lessThan] = lessThanState;
Table[lessThanState][greaterThan] = lessThanFinal;
Table[lessThanState][exlimation] = lessThanFinal;
Table[lessThanState][leftparen] = lessThanFinal;
Table[lessThanState][rightparen] = lessThanFinal;
Table[lessThanState][leftbrace] = lessThanFinal;
Table[lessThanState][rightbrace] = lessThanFinal;
Table[lessThanState][comma] = lessThanFinal;
Table[lessThanState][semicolon] = lessThanFinal;
Table[lessThanState][WS] = lessThanFinal;
Table[lessThanState][other] = error;

//greater than state
Table[greaterThanState][letter] = greaterThanFinal;
Table[greaterThanState][digit] = greaterThanFinal;
Table[greaterThanState][astrix] = greaterThanFinal;
Table[greaterThanState][plusType] = greaterThanFinal;
Table[greaterThanState][minusType] = greaterThanFinal;
Table[greaterThanState][divisor] = greaterThanFinal;
Table[greaterThanState][equals] = greaterThanEqualsStateFinal;
Table[greaterThanState][lessThan] = greaterThanFinal;
Table[greaterThanState][greaterThan] = greaterThanState;
Table[greaterThanState][exlimation] = greaterThanFinal;
Table[greaterThanState][leftparen] = greaterThanFinal;
Table[greaterThanState][rightparen] = greaterThanFinal;
Table[greaterThanState][leftbrace] = greaterThanFinal;
Table[greaterThanState][rightbrace] = greaterThanFinal;
Table[greaterThanState][comma] = greaterThanFinal;
Table[greaterThanState][semicolon] = greaterThanFinal;
Table[greaterThanState][WS] = greaterThanFinal;
Table[greaterThanState][other] = error;



//exclemation state
Table[exclemationState][letter] = NotstateFinal;
Table[exclemationState][digit] = NotstateFinal;
Table[exclemationState][astrix] = NotstateFinal;
Table[exclemationState][plusType] = NotstateFinal;
Table[exclemationState][minusType] = NotstateFinal;
Table[exclemationState][divisor] = NotstateFinal;
Table[exclemationState][equals] = notEqualsStateFinal;
Table[exclemationState][lessThan] = NotstateFinal;
Table[exclemationState][greaterThan] = NotstateFinal;
Table[exclemationState][exlimation] = NotstateFinal;
Table[exclemationState][leftparen] = NotstateFinal;
Table[exclemationState][rightparen] = NotstateFinal;
Table[exclemationState][leftbrace] = NotstateFinal;
Table[exclemationState][rightbrace] = NotstateFinal;
Table[exclemationState][comma] = NotstateFinal;
Table[exclemationState][semicolon] = NotstateFinal;
Table[exclemationState][WS] = NotstateFinal;
Table[exclemationState][other] = error;
}

    


