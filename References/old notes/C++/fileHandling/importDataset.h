#ifndef _importDataset_h
#define _importDataset_h

#include "moneyRemittance.h"
#include <fstream>    //file handling
#include <string>     // srtring data
#include <bits/stdc++.h>   //stl containers
#include <cstdlib>


MoneyRemittance parseData(std::string line) {        //Line input
    
    std::string word;
    std::stringstream s(line); 
    std::vector<std::string> lineData;   

    lineData.clear();
    while (getline(s, word, ',')) { 
    lineData.push_back(word);
    } 
    double iniBal = std::atof(lineData[6].c_str());
    MoneyRemittance d1(lineData[0],lineData[1],lineData[2],lineData[3],lineData[4],lineData[5],iniBal);
    
    return d1;
} 


std::list<MoneyRemittance> importDataset(std::string fileName){

std::list<MoneyRemittance> mrCust;
std::string line;
std::ifstream file;  // define file handler

file.open(fileName);
    while(std::getline(file,line)){
    MoneyRemittance pData = parseData(line);
    mrCust.push_back(pData);
    }
 
return mrCust;

}//Import end




#endif
