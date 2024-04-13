#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "lexical.h"
#include "symbol.h"
#include "States.h"
#include "Files.h"

using namespace std;


int main()
{
    FSA fsa;
    Files files;
    Lexical Lex(fsa);
    string input = files.read("Prgm.txt");
    cout << "Program read:\n " << input << endl;
    Lex.setInput(input);
    Lex.tokenize(input);
    Tokens* tokens = Lex.getTokens();
    size_t tokenCount = Lex.getTokenCount();
    for(size_t i = 0; i < Lex.getTokenCount(); i++)
    {
        cout << setw(20) << left << tokens[i].lexeme << setw(20) << right << tokens[i].tokenType << endl;
    }
    symbolTable symTable;
    symTable.symTable(tokens[0], tokens, tokenCount);
    symbol* symbols = symTable.getSymbols();
    cout << "Symbol Table:\n";
    cout << setw(20) << left << "Symbol" << setw(20) << "Classification" << setw(20) << "Value" << setw(20) << "Address" << setw(20) << "Segment" << endl;
    for(size_t i = 0; i < symTable.getSymbolCount(); i++)
    {
        cout << setw(20) << left << symbols[i].syms << setw(20) << symbols[i].Classification << setw(20) << symbols[i].value << setw(20) << symbols[i].address << setw(20) << symbols[i].segment << endl;
    }




    return 0;
}


