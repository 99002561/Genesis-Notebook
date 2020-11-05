#ifndef _cricket_h
#define _cricket_h

#include "player.h"
using namespace std;


class cricket:public player{

string p_class;
string p_role;
string p_odiCount;


public:
cricket();
//Name,DOB,Place,Class,Role,ODI Cnt
cricket(string,string,string,string,string,string);

string getPlayerClass();
string getPlayerRole();
string getPlayerOdiCount();





};




#endif