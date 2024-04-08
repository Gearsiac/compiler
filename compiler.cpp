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
#include "States.h"
#include "FSA.h"
#include "Files.h"
#include "symbol.h"
using namespace std;

symbolstates symStateError = symStateError;
symbolstates symStateStart = symStateStart;
symbolTable symTable;
int main()
{
    FSA fsa;
    Lexical lex(fsa);
    Files file;
    string input = file.read("Prgm.txt");
    cout << "Input Read from File:" << endl << input << endl;
    lex.setInput(input);
    lex.tokenize(input); 
    vector<Tokens>& tokens = lex.getTokens();
    cout << "Lexical Analysis Result:" << endl;
    cout << "Lexeme" << "Token Type" << endl;
    for (const auto& token : tokens) {
        cout << setw(20) << left << token.lexeme << token.tokenType << endl;
    }
    


    

    return 0;
}


