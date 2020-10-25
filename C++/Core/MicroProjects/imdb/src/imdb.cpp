#include "imdb.h"

IMDB::IMDB():
Movie(),
m_rating(""),
m_VoteCnt("")
{}


IMDB::IMDB(string mtitle,string mCrtor,string mCntry,string mYear,string mGen,string rat,string VtCnt):
Movie(mtitle,mCrtor,mCntry,mYear,mGen),
m_rating(rat),
m_VoteCnt(VtCnt)
{}

string IMDB::getRating(){
return m_rating;
}

string IMDB::getVoteCount(){
    return m_VoteCnt;
}

void IMDB::display(){

cout << "Movie Details: " << endl;
cout << "Title:" + m_title << endl;
cout << "Director:" + m_creator << endl;
cout << "Country:" + m_country << endl;
cout << "Year:" + m_year << endl;
cout << "Genre:" + m_genre << endl;
//cout << "IMDB Rating:" + m_rating << endl;
//cout << "Total Votes Received:" + m_VoteCnt << endl;

}
