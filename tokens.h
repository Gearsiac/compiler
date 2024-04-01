#include <iostream>
#include <string>
#include "tokensates.h"
using namespace std;

class Tokens
{
    private:
    Tokens();
    state Table[StateCount][typeCount];
    public:
    state nextState(state currentState, types inputType);

};