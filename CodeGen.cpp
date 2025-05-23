#include <iostream>
#include <iomanip>
#include <string>
#include "Parse.h"
#include "symbol.h"
#include "EnumerationTypes.h"
#include "CodeGen.h"
using namespace std;

stringstream asmCode;

CodeGen :: CodeGen(){};

void CodeGen :: Linix()
{
    asmCode <<"sys_exit\tequ\t1\n";
    asmCode <<"sys_read\tequ\t3\n";
    asmCode <<"sys_write\tequ\t4\n";
    asmCode <<"stdin\tequ\t0\n";
    asmCode <<"stdout\tequ\t1\n";
    asmCode <<"stder\tequ\t3\n";
}
void CodeGen :: GenerateData(symbol* symbols, int symbolCount)
{
    asmCode << "section\t.data\n";
    asmCode << "\tuserMsg\tdb\t'Enter an Integer:'\n";
    asmCode << "\tlenUserMsg\tequ\t$-userMsg\n";
    asmCode << "\tdisplayMsg\tdb\t'You entered: '\n";
    asmCode << "\tlenDisplayMsg\tequ\t$-displayMsg\n";
    asmCode << "\tnewline\tdb\t0xA\n";
    
    asmCode << "\tTen\tDW\t10\n";

    asmCode << "\tResult\tdb\t'Ans = '\n";
    asmCode << "\tResultValue\tdb\t'aaaaa'\n";
    asmCode << "\tdb\t0xA\n";
    asmCode << "\tResultEnd\tequ\t$-Result\n";

    asmCode << "\tnum\ttimes\t6\tdb\t'ABCDEF'\n";

    asmCode << "\tnumEnd\tequ\t$-num\n";


   for(int i = 0; i < symbolCount; i++)
{
    if(symbols[i].Classification == "CONST"|| symbols[i].Classification == "Numeric Literal")
    {
        bool alreadyProcessed = false;
        for(int j = 0; j < i; j++)
        {
            if(symbols[j].value == symbols[i].value)
            {
                alreadyProcessed = true;
                break;
            }
        }

        if(!alreadyProcessed)
        {
            asmCode << "\t" << symbols[i].syms << "\tDW\t" << symbols[i].value << "\n";
        }
    }
}


}
void CodeGen :: GenerateBss(symbol* symbols, int symbolCount)
{
    asmCode << "section\t.bss\n";
    asmCode << "\tTempChar\tRESB\t1\n";
    asmCode << "\ttestchar\tRESB\t1\n";
    asmCode << "\tReadInt\tRESW\t1\n";
    asmCode << "\tTempint\tRESW\t1\n";
    asmCode << "\tnegflag\tRESB\t1\n";

    for(int i = 0; i < symbolCount; i++)
    {
        if(symbols[i].Classification == "VAR" || symbols[i].Classification == "Var (int)")
        {
            asmCode << "\t"<< symbols[i].syms << "\tRESW\t1\n";
        }
    }


}
void CodeGen :: GenerateAssembly(Quads* quads, int quadCount)
{   asmCode << "global\t_start\n";
    asmCode << "section\t.text\n";
    asmCode << "_start:\tnop\n";
    for(int i = 0; i < quadCount; i++)
    {
        Quads quad = quads[i];
        string op = quad.op;
        string arg1 = quad.arg1;
        string arg2 = quad.arg2;
        string result = quad.Temp;
        if(op == "CIN"){

            asmCode << "\tcall PrintString\n";
            asmCode << "\tcall GetAnInteger\n";
            asmCode << "\tmov\tax,[ReadInt]\n";
            asmCode << "\tmov\t[" << arg1 << "],ax\n";

        }
        if(op == "+")
        {
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tadd\tax,["<< arg2 <<"]\n";
            asmCode << "\tmov\t["<< result <<"],ax\n";
        }
        if(op == "-")
        {
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tsub\tax,["<< arg2 <<"]\n";
            asmCode << "\tmov\t["<< result <<"],ax\n";
        }
        if(op == "*")
        {
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tmul\tword\t["<< arg2 <<"]\n";
            asmCode << "\tmov\t["<< result <<"],ax\n";
        
        }
        if(op == "/")
        {
            asmCode << "\tmov\tdx,0\n";
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tmov\tcx,["<< arg2 <<"]\n";
            asmCode << "\tdiv\tcx\n";
            asmCode << "\tmov\t["<< result <<"],ax\n";

        }
        if(op == "="){
            asmCode << "\tmov\tax,["<< arg2 << "] \n";
            asmCode << "\tmov\t["<< arg1 <<"],ax\n";
        }
        if(op == ">"){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcmp\tax,["<< arg2 <<"]\n";
        }
        if(op == ">="){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcmp\tax,["<< arg2 <<"]\n";
        }
        if(op == "<"){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcmp\tax,["<< arg2 <<"]\n";
        }
        if(op == "<="){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcmp\tax,["<< arg2 <<"]\n";
        }
        if(op == "=="){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcmp\tax,["<< arg2 <<"]\n";
        }
        if(op == "!="){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcmp\tax,["<< arg2 <<"]\n";
        }
        if(op == "THEN")
        {
            asmCode << "\t"<< arg2 <<" "<< arg1 << "\n";
        }
        if(op == "ELSE"){
            asmCode << "\tJMP\t"<< arg1 <<"\n";
        }
        if(op == "WHILE")
        {
            asmCode << arg1 <<":\n";
        }
        if(op == "DO")
        {
            asmCode << "\t"<< arg2 <<" "<< arg1 << "\n";
        }
        if(op == "JMP")
        {
             asmCode << "\tJMP\t"<< arg1 <<"\n";

        }
        if(op == "J"){
            asmCode << ""<< arg1 << ":\tnop\n";
        }
        if(op == "COUT"){
            asmCode << "\tmov\tax,["<< arg1 <<"] \n";
            asmCode << "\tcall ConvertIntegerToString\n";
            asmCode << "\tmov\teax, 4\n";
            asmCode << "\tmov\tebx, 1\n";
            asmCode << "\tmov\tecx, Result\n";
            asmCode << "\tmov\tedx, ResultEnd\n";
            asmCode << "\tint\t80h\n";
        }
    }
}
void CodeGen :: IOSection()
{
    asmCode << "fini:\n";
    asmCode << "\tmov\teax,sys_exit\n";
    asmCode << "\txor\tebx,ebx\n";
    asmCode << "\tint\t80h\n";

    asmCode << "PrintString:\n";
    asmCode << "\tpush ax\n";
    asmCode << "\tpush dx\n";
    asmCode << "\tmov\teax, 4\n"; 
    asmCode << "\tmov\tebx, 1\n"; 
    asmCode << "\tmov\tecx, userMsg\n";
    asmCode << "\tmov\tedx, lenUserMsg\n";
    asmCode << "\tint\t80h\n";
    asmCode << "\tpop\tdx\n";
    asmCode << "\tpop\tax\n";
    asmCode << "\tret\n";

    asmCode << "GetAnInteger:\n";
    asmCode << "\tmov\teax, 3\n"; 
    asmCode << "\tmov\tebx, 2\n"; 
    asmCode << "\tmov\tecx, num\n";
    asmCode << "\tmov\tedx, 6\n";
    asmCode << "\tint\t0x80\n";
    asmCode << "\tmov\tedx,eax\n";
    asmCode << "\tmov\teax, 4\n"; 
    asmCode << "\tmov\tebx, 1\n"; 
    asmCode << "\tmov\tecx, num\n";
    asmCode << "\tint\t80h\n";

    asmCode << "ConvertStringToInteger:\n";
    asmCode << "\tmov\tax, 0\n";
    asmCode << "\tmov\t[ReadInt], ax\n";
    asmCode << "\tmov\tecx,num\n";
    asmCode << "\tmov\tbx, 0\n";
    asmCode << "\tmov\tbl, byte [ecx]\n";
    asmCode << "Next:\n";
    asmCode << "\tsub\tbl,'0'\n";
    asmCode << "\tmov\tax,[ReadInt]\n";
    asmCode << "\tmov\tdx, 10\n";
    asmCode << "\tmul\tdx\n";
    asmCode << "\tadd\tax,bx\n";
    asmCode << "\tmov\t[ReadInt],ax\n";
    asmCode << "\tmov\tbx,0\n";
    asmCode << "\tadd\tecx,1\n";
    asmCode << "\tmov\tbl, byte[ecx]\n";
    asmCode << "\tcmp\tbl,0xA\n";
    asmCode << "\tjne\tNext\n";
    asmCode << "\tret\n";

    asmCode << "ConvertIntegerToString:\n";
    asmCode << "\tmov\tebx, ResultValue + 4\n";

    asmCode << "ConvertLoop:\n";
    asmCode << "\tsub\tdx, dx\n";
    asmCode << "\tmov\tcx, 10\n";
    asmCode << "\tdiv\tcx\n";
    asmCode << "\tadd\tdl, '0'\n";
    asmCode << "\tmov\t[ebx], dl\n";
    asmCode << "\tdec\tebx\n";
    asmCode << "\tcmp\tebx, ResultValue\n";
    asmCode << "\tjge\tConvertLoop\n";
    asmCode << "\tret\n";


}

//still need to create ASM specific file writer 
void CodeGen :: CreateASMFile()
{
    ofstream file("Prgm.asm");
    if(!file.is_open())
    {
        cerr << "Error: Unable to open file output.asm" << endl;
        exit(1);
    }
    file << asmCode.str();
    file.close();
   
}
