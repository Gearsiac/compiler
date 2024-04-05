#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "files.h"
#include "lexical.h"

using namespace std;

string Files::read(const string& filename) const
{
    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
void Files::write(const vector<Tokens>& tokens)
{
    ofstream file("output.txt");
    for (auto& token : tokens)
    {
        file << token.lexeme << " " << token.tokenType << endl;
    }
}
void Files::readlist()
{
    string filename;
    cout << "Enter the name of the file you want to read: ";
    cin >> filename;
    cout << read(filename);
}

