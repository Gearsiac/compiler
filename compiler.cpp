#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "lexical.h"
#include "States.h"
#include "FSA.h"
#include "Files.h"
#include "symbol.h"
using namespace std;


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
        cout << setw(20) << left << token.lexeme << setw(20) << right << token.tokenType << endl;
    }
    cout << endl;
    symbolTable symTable;
    symTable.symTable(tokens[0], tokens); // Call this only once, outside of the loop
    vector<symbol>& symbols = symTable.getSymbols();
    cout << "Symbol Table:" << endl;
    cout << setw(20) << left << "Symbol" << setw(20) << "Classification" << setw(20) << "Value" << setw(20) << "Address" << setw(20) << "Segment" << endl;
    for (const auto& symbol : symbols) {
        cout << setw(20) << left << symbol.syms << setw(20) << symbol.Classification << setw(20) << symbol.value << setw(20) << symbol.address << setw(20) << symbol.segment << endl;
    }
    cout << endl;
    return 0;
}


