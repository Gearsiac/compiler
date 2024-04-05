#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "files.h"
#include "lexical.h"

using namespace std;

files file;
string files::read(const string& filename) const
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: could not open file " << filename << endl;
        exit(1);
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
void files :: write(const vector<Tokens>& tokens)
{
    ofstream file("output.txt");
    if (!file)
    {
        cerr << "Error: could not open file output.txt" << endl;
        exit(1);
    }
    for (const auto& token : tokens)
    {
        file << left << setw(20) << token.lexeme << token.tokenType << endl;
    }
}
void files :: readlist()
{
    string filename;
    cout << "Enter the name of the file you want to read: ";
    cin >> filename;
    string content = read(filename);
    cout << content << endl;
}