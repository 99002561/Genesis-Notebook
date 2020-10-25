
#include "cricketDB.h"
#include <iostream>

void playerBase::addPlayer(string name,string dob,string place,string cls,string role,string odiNo){
l_players.push_back(cricket(name,dob,place,cls,role,odiNo));
}

void playerBase::addPlayer(vector<string> data){
l_players.push_back(cricket(data[0],data[1],data[2],data[3],data[4],data[5]));    
}


void playerBase::importDataset(string fileName){

ifstream file;  // define file handler in readmode
string line,dataField;

file.open(fileName);

getline(file,line);  //Read 1st line
vector<string> lineData;

    while(getline(file,line)){     //Read from 2nd Line
        stringstream s(line);  // Converting datatype
        while (getline(s, dataField,',')) {     //extract dataFiled into vector
        lineData.push_back(dataField);
        }
        addPlayer(lineData);
        lineData.clear();
    }

file.close();

}//Import end

cricket* playerBase::getPlayerRecords(string name){

list<cricket>::iterator iter;


    for(iter=l_players.begin();iter!=l_players.end();iter++){
        string tempName = iter->getPlayerName();
       // cout << tempName << endl;
        if(name == tempName){
            return &(*iter);
        }
    }
    return NULL;


}