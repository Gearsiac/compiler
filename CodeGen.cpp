#include <iostream>
#include <iomanip>
#include <string>
#include "Parse.h"
#include "symbol.h"
#include "EnumerationTypes.h"
#include "Files.h"
#include "CodeGen.h"
using namespace std;

stringstream asmCode;
void CodeGen :: LinixLinking()
{
    asmCode <<"sys_exit\tequ\t1\n";
    asmCode <<"sys_read\tequ\t3\n";
    asmCode <<"sys_write\tequ\t4\n";
    asmCode <<"stdin\tequ\t0\n";
    asmCode <<"stdout\tequ\t1\n";
    asmCode <<"stder\tequ\t3\n";
}
void GnerateData(symbol* symbols, int symbolCount)
{

}
void CodeGen :: IOSection()
{

}
void CodeGen :: ProcessQuads()
{
    
}