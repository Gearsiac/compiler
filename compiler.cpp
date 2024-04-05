#include <iostream>
#include <string>
#include <vector>
#include "lexical.h"    
#include "States.h"
#include "FSA.h"
#include "Files.h"
using namespace std;

int main()
{
    FSA fsa;
    Lexical lex(fsa);
    Files file;
    string input = file.read("Prgm.txt");
    lex.setInput(input);
    lex.tokenize();
    file.write(lex.getTokens());
    return 0;
}

