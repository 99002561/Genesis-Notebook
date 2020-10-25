#include "billing.h"
#include <bits/stdc++.h> 

void Billing::addBill(string name,string num,string bNum,string bDate,double bAmount){
    l_bills.push_back(PatientBill(name,num,bNum,bDate,bAmount));
}


void Billing::addBill(PatientBill b1){
    l_bills.push_back(b1);
}




void Billing::addBill(vector<string> data){
double amt = atof(data[4].c_str());

l_bills.push_back(PatientBill(data[0],data[1],data[2],data[3],amt));

}


void Billing::importDataset(string fileName){

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
        addBill(lineData);
        lineData.clear();
    }

file.close();

}//Import end





bool Billing::discharge(string billNo){

list<PatientBill>::iterator iter;


    for(iter=l_bills.begin();iter!=l_bills.end();iter++){
        
        if(iter->getBillNum() == billNo){
            l_bills.erase(iter);
            return true;
        }

    }

    return false;

}

PatientBill* Billing::findBill(string billNo){

list<PatientBill>::iterator iter;


    for(iter=l_bills.begin();iter!=l_bills.end();iter++){
        
        if(iter->getBillNum() == billNo){
            return &(*iter);
        }

    }

    return NULL;



}