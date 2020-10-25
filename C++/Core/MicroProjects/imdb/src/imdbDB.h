#ifndef _imdbd_h
#define _imdbd_h

#include "imdb.h"
#include <list>
#include <string>
#include <vector>
//#include <iostream>
#include <fstream>    //file handling
#include <bits/stdc++.h>  

using namespace std;


class IMDBdatabase{

list<IMDB> l_movies;
IMDB nullObj;  

public:


void importDataset(string fileName);

void addMovie(string,string,string,string,string,string,string);
void addMovie(IMDB);
void addMovie(vector<string> data);

IMDB* findMovie_byName(string);
void showMovies_byRating(string);



};






#endif