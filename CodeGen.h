#ifndef CODEGEN_H
#define CODEGEN_H
#include <iostream>
#include <iomanip>
#include <string>
#include "lexical.h"
#include "Parse.h"
#include "symbol.h"
#include "EnumerationTypes.h"
using namespace std;

class CodeGen
{
    private:
        Quads* quads; // Quads
        void LinixLinking(); // Linux configuration
        void GenerateData(symbol* symbols, int symbolCount); // Generate code
        void IOSection(); // IO section

     public:
        CodeGen(); // Constructor
        void ProcessQuads(); // Process quads
        void CreateASMFile(); // Create ASM file
};
#endif