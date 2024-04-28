#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "CodeGen.h"
#include "Parse.h"
#include "lexical.h"
#include "symbol.h"
#include "EnumerationTypes.h"
#include "Files.h"
using namespace std;

int main()
{
    Files files; // Create an instance of the Files class
    Lexical Lex; // Create an instance of the Lexical class
    string input = files.read("Prgm.txt"); // Read the file
    Lex.setInput(input); // Set the input
    Lex.tokenize(input); // Tokenize the input
    Tokens* tokens = Lex.getTokens(); // Get the tokens
    int tokenCount = Lex.getTokenCount(); // Get the token count
    symbolTable symTable; // Create an instance of the symbolTable class
    symTable.symTable(tokens[0], tokens, tokenCount); // Symbol table
    symTable.getSymbolCount(); // Get the symbol count
    symTable.getSymbols(); // Get the symbols
    for(int i = 0; i < symTable.getSymbolCount(); i++) // Print the symbols
    {
        cout << symTable.getSymbols()[i].syms << " " << symTable.getSymbols()[i].Classification << " " << symTable.getSymbols()[i].value << endl;
    }
    Parse parse; // Create an instance of the Parse class
    parse.Parseing(tokens[0], tokens, tokenCount); // Parse
    Quads* quads = parse.getParseQuads(); // Get the parse quads
    int quadCount = parse.getQuadsCount(); // Get the quad count
    CodeGen codeGen; // Create an instance of the CodeGen class
    codeGen.LinixCommands(); // Linux configuration
    codeGen.GenerateData(symTable.getSymbols(), symTable.getSymbolCount()); // Generate data
    codeGen.GenerateBss(symTable.getSymbols(), symTable.getSymbolCount()); // Generate BSS
    codeGen.GenerateAssembly(quads, quadCount); // Generate assembly
    codeGen.IOSection(); // IO section
    codeGen.CreateASMFile(); // Create the ASM file

 
    
    
 
    
   
    
    
    return 0;
}


