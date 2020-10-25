#ifndef _cricketDB_h
#define _cricketDB_h

#include <list>
#include <vector>
#include "cricket.h"
#include <fstream>
#include <bits/stdc++.h> 


using namespace std;

class playerBase{
list<cricket> l_players;

public:

void addPlayer(string,string,string,string,string,string);
void addPlayer(vector<string>);

void importDataset(string fileName);

//Analysis
cricket* getPlayerRecords(string name);




};




#endif