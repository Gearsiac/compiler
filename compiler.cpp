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
    Files files; // Create an instance of the Files class
    Lexical Lex; // Create an instance of the Lexical class
    string input = files.read("Prgm.txt"); // Read the file
    Lex.setInput(input); // Set the input
    Lex.tokenize(input); // Tokenize the input
    Tokens* tokens = Lex.getTokens(); // Get the tokens
    size_t tokenCount = Lex.getTokenCount(); // Get the token count
    

    return 0;
}


