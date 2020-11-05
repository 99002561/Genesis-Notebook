#include"patient.h"


Patient::Patient():
	p_name(""),    
	p_Mobnum("")    
{}

Patient::Patient(string name,string MobNum):
	p_name(name),     
	p_Mobnum(MobNum)    
{}

string Patient::getPatientName(){
	return p_name;
}

string Patient::getPatientNum(){
	return p_Mobnum;
}

string Patient::display(){
cout << p_name << "," << p_Mobnum << endl;
return "Patient Details";
}



