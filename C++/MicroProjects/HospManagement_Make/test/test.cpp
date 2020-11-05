#include "../src/patientbill.h"
#include <gtest/gtest.h>
#include "../src/billing.h"

#define _cmake_
//#define _command_

#ifdef _cmake_

#include "../src/billing.cpp"
#include "../src/patientbill.cpp"
#include "../src/patient.cpp"

#endif

TEST(Patient,Constructor){
Patient p1("Mr.Abc","9900262311");
EXPECT_EQ(6,p1.getPatientName().length());
p1.display(); 
}

TEST(PatientBill,Constructor){
PatientBill p1("Mr.Abc","9900262311","0001","25/01/2018",5000);
ASSERT_EQ(5000,p1.getBillAmount());

p1.display();
}

TEST(PatientBill,Charges){
PatientBill b1("Mr.Abc3","9900262314","0004","28/01/2018",0);
b1.charge(5000); // treatmentCharge
b1.charge(2000);//bed Charges
b1.charge(500);// Misc

ASSERT_EQ(7500,b1.getBillAmount());
}

TEST(PatientBill,DynamicBinding){
PatientBill b1("Mr.Abc3","9900262314","0004","28/01/2018",7000);
Patient *p1 = &b1;
EXPECT_EQ("Bill Details",p1->display());  
}

TEST(Billing,addPatient){
Billing bills;

bills.addBill("Mr.Abc","9900262311","0001","25/01/2018",5000);
bills.addBill("Mr.Abc1","9900262312","0002","26/01/2018",2000);
bills.addBill("Mr.Abc2","9900262313","0003","27/01/2018",3000);
bills.addBill("Mr.Abc3","9900262314","0004","28/01/2018",1000);

EXPECT_EQ((PatientBill*)NULL, bills.findBill("0005"));

PatientBill* b1 = bills.findBill("0004");
EXPECT_EQ(1000,b1->getBillAmount());   //static binding

}

TEST(Billing,addPatientDB){
Billing bills;

bills.importDataset("dataBase.csv");
EXPECT_EQ((PatientBill*)NULL, bills.findBill("0005"));

PatientBill* b1 = bills.findBill("0004");
EXPECT_EQ(2000,b1->getBillAmount());   //static binding

}

TEST(Billing,Discharge){

Billing bills;


bills.addBill("Mr.Abc","9900262311","0001","25/01/2018",5000);
bills.addBill("Mr.Abc1","9900262312","0002","26/01/2018",2000);
bills.addBill("Mr.Abc2","9900262313","0003","27/01/2018",3000);
bills.addBill("Mr.Abc3","9900262314","0004","28/01/2018",1000);

bills.discharge("0004");
EXPECT_EQ((PatientBill*)NULL, bills.findBill("0004"));

}

TEST(Billing,dischargeDB){
Billing bills;

bills.importDataset("dataBase.csv");
bills.discharge("0004");
EXPECT_EQ((PatientBill*)NULL, bills.findBill("0004"));

}





int main(int argc, char **argv) {
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
    


