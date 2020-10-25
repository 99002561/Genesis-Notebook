#include "patientbill.h"

PatientBill::PatientBill():
Patient(),
b_num(""),
b_date(""),
b_amt(0.0)
{}

PatientBill::PatientBill(string name,string num,string bNum,string bDate,double bAmount):
Patient(name,num),
b_num(bNum),
b_date(bDate),
b_amt(bAmount)
{}

void PatientBill::charge(double charAMT){
	b_amt += charAMT;
}

string PatientBill::getBillNum(){
	return b_num;
}

string PatientBill::getBillDate(){
	return b_date;
}

double PatientBill::getBillAmount(){
	return b_amt;
}

string PatientBill::display(){
	cout << "\nPatient Details : " + p_name + "," + p_Mobnum << endl;
	cout << "Bill Details: " << b_num << "," << b_date << "," << b_amt << endl << '\n';
	return "Bill Details";
}