#ifndef __PATIENT_H
#define __PATIENT_H

#include <string>
#include <iostream>

using namespace std;

class Patient
{

protected: // Parameters accessible for derived classes also
  string p_name;
  string p_Mobnum;

public:
  Patient();
  Patient(string, string); // Name,MobNumber

  string getPatientName();
  string getPatientNum();

  virtual string display();
};

#endif
