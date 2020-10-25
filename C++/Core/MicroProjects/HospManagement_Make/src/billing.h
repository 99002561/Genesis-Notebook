#ifndef _billing_h
#define _billing_h


#include "patientbill.h"
#include <list>
#include <vector>
#include <fstream>
//

using namespace std;


class Billing{

list<PatientBill> l_bills;

public:


//Name,MobNum,Bill No.,Date,Amount
void addBill(string,string,string,string,double);
void addBill(PatientBill);
void addBill(vector<string> data);  // To add imported data

void importDataset(string fileName);

// Tasks
PatientBill* findBill(string); //bill_no
bool discharge(string);//bill_no




};







#endif