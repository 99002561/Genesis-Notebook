#ifndef _movies_h
#define _movies_h

#include <string>

using namespace std;



class Movie{

protected :
string m_title;
string m_creator;
string m_country;
string m_year;
string m_genre;

public:

Movie();
Movie(string f_title,string f_creator,string f_country,string f_year,string f_genere);

string getTitle();
string getCreator();
string getCountry();
string getYear();
string getGenre();

virtual void display()=0;


};






#endif