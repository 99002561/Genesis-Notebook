#ifndef _imdb_h
#define _imdb_h

#include "movies.h"
#include <iostream>

using namespace std;

class IMDB : public Movie
{
protected:
string m_rating;
string m_VoteCnt;

public:

IMDB();
IMDB(string,string,string,string,string,string,string);

string getRating();
string getVoteCount();

void display();

};


#endif