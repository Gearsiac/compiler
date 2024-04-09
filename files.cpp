#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "files.h"
#include "lexical.h"

using namespace std;

string Files::read(const string& filename) const
{
    ifstream file(filename);
    string line;
    string text;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            text += line + "\n";
        }
        file.close();
    }
    return text;
}
void Files::write(const vector<Tokens>& tokens)
{
    ofstream file("output.txt");
    if (file.is_open())
    {
        for (const auto& token : tokens)
        {
            file << left << setw(20) << token.lexeme << token.tokenType << endl;
        }
        file.close();
    }
}
