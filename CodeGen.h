#ifndef CODEGEN_H
#define CODEGEN_H
#include <iostream>
#include <iomanip>
#include <string>
#include "lexical.h"
#include "Parse.h"
#include "symbol.h"
#include "EnumerationTypes.h"
#include "Files.h"
using namespace std;

class CodeGen
{
    private:
    

     public:
        CodeGen(); // Constructor
        void GenerateAssembly(Quads* quads, int quadCount); // Process quads
        void CreateASMFile(); // Create ASM file
        void Linix(); // Linux configuration
        void GenerateData(symbol* symbols, int symbolCount); // Generate code
        void GenerateBss(symbol* symbols, int symbolCount); // Generate BSS
        void IOSection(); // IO section
};
#endif