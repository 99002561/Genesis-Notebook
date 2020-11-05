#include "player.h"

player::player():
    p_name(""),
    p_dob(""),
    p_place("")
{}

player::player(string name,string dob,string place):

    p_name(name),
    p_dob(dob),
    p_place(place)
{}


string player::getPlayerName(){
    return p_name;
}


string player::getPlayerDob(){
    return p_dob;
}


string player::getPlayerPlace(){
    return p_place;
}

