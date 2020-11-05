#include "movies.h"
#include <iostream>

Movie::Movie():
m_title(""),
m_creator(""),
m_country(""),
m_year(""),
m_genre(""){}

Movie::Movie(string f_title,string f_creator,string f_country,string f_year,string f_genere):
m_title(f_title),
m_creator(f_creator),
m_country(f_country),
m_year(f_year),
m_genre(f_genere){}


string Movie::getTitle(){
    return m_title;
}

string Movie::getCreator(){
    return m_creator;
}

string Movie::getCountry(){
    return m_country;
}

string Movie::getYear(){
return m_year;
}

string Movie::getGenre(){
    return m_genre;
}

/*void Movie::display(){

cout << "Movie Details: " << endl;
cout << "Title:" + m_title << endl;
cout << "Director:" + m_creator << endl;
cout << "Country:" + m_country << endl;
cout << "Year:" + m_year << endl;
cout << "Genre:" + m_genre << endl;
}*/