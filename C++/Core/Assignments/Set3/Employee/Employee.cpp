#include<iostream>
#include"Employee.h"
#include"Engineer.h"
#include"Trainee.h"
#include"Manager.h"
using namespace std;

Employee::Employee(string id, string name, double salary,int exp):
    m_empid(id),m_name(name),m_salary(salary),m_exp(exp){

}
Engineer::Engineer(string eid, string ename, double esalary,int eexp,int ecode):Employee(eid,ename,esalary,eexp),m_projCode(ecode){

}
Manager::Manager(string eid, string ename, double esalary,int eexp,int ecode,int ereportees):Employee(eid,ename,esalary,eexp),m_projCode(ecode),m_reportees(ereportees){

}
Trainee::Trainee(string eid, string ename, double esalary,string track ,double score):Employee(eid,ename,esalary,0),m_track(track),score(score){

}
int Engineer::payroll()
{
return m_salary;
}
int Manager::payroll()
{
return m_salary;
}
int Trainee::payroll()
{
return m_salary;
}
int Engineer::appraisal(int app)
{
m_salary += app;
return m_salary;
}
int Manager::appraisal(int app)
{
m_salary += app;
return m_salary;
}
int Trainee::appraisal(int app)
{
m_salary += app;
return m_salary;
}
void Engineer::display()
{
	std::cout<<
}
void Manager::display()
{

}
void Trainee::display()
{

}
