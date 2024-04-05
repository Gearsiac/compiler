#ifndef TOKENS_H
#define TOKENS_H
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
using namespace std;

const int Nstates = static_cast<int>(StateCount);
const int Nintputs = static_cast<int>(typeCount);

class FSA
{
private:
    int Table[Nstates][Nintputs] = {};
    void FSAConfig();
    
public:
    FSA();
    state nextState(state currentState, types input);
};


#endif