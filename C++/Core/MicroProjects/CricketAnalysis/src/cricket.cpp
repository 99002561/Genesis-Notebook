#include "cricket.h"


cricket::cricket():
player(),
p_class(""),
p_role(""),
p_odiCount("")
{}

cricket::cricket(string name,string dob,string place,string cls,string role,string odiNo):
player(name,dob,place),
p_class(cls),
p_role(role),
p_odiCount(odiNo)
{}

string cricket::getPlayerClass(){
    return p_class;
}

string cricket::getPlayerRole(){
    return p_role;
}

string cricket::getPlayerOdiCount(){
    return p_odiCount;
}