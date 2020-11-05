#ifndef PATIENTBILL_H_INCLUDED
#define PATIENTBILL_H_INCLUDED

#include "patient.h"
#include <string>
//#include <list>
//#include <iterator>

using namespace std;

class PatientBill : public Patient
{
	string b_num;
	string b_date;
	double b_amt; 

	public:
	
	PatientBill();
	//Name,MobNum,Bill No.,Date,Amount
	PatientBill(string,string,string,string,double);

	void charge(double);

	string getBillNum();
	string getBillDate();
	double getBillAmount();

	string display();


	
};

#endif
