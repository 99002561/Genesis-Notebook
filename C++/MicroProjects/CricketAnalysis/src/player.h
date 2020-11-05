#ifndef _player_h
#define _player_h

#include <string>

using namespace std;

class player
{
protected:
   string p_name;
   string p_dob;
   string p_place;


public:
    player();
    player(string,string,string);

    

    string getPlayerName();
    string getPlayerDob();
    string getPlayerPlace();

};








#endif