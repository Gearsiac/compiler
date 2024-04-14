#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "files.h"
#include "lexical.h"
using namespace std;
string Files::read(const string &files) const // Read the file
{
    ifstream file(files); // Open the file
    if(!file.is_open()) // Check if the file is open
    {
        cerr << "Error: Unable to open file " << files << endl; // Display an error message
        exit(1); // Exit the program
    }
    stringstream buffer; // Create a string stream
    buffer << file.rdbuf(); // Read the file buffer
    file.close(); // Close the file after reading
    return buffer.str(); // Return the buffer as a string
}
void Files::write(const string &files, const string &output) const // Write to the file
{
    ofstream file(files); // Open the file
    if(!file.is_open()) // Check if the file is open
    {
        cerr << "Error: Unable to open file " << files << endl; // Display an error message
        exit(1); // Exit the program
    }
    file << output; // Write the output to the file
    file.close(); // Close the file after writing
}