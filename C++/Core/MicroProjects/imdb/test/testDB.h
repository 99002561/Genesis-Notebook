#include "imdbDB.h"
//#include <gtest/gtest.h>

void dataBase_test(){

IMDBdatabase db;

db.importDataset("IMDBratings.csv");
//db.addMovie("xyz","raj","Ind","2020","Horror","5.5","150");

/*
db.addMovie("xyz","raj","Ind","2020","Horror","5.5","150");
db.addMovie("xyz1","raj","Ind","2020","Horror","4","150");
db.addMovie("xyz2","raj","Ind","2020","Horror","6","150");
db.addMovie("xyz3","raj","Ind","2020","Horror","7","150");
db.addMovie("xyz4","raj","Ind","2020","Horror","8","150");
db.addMovie("xyz5","raj","Ind","2020","Horror","3","150");*/

db.showMovies_byRating("5");


cout << "\nDisplaying Contents of Derived Class \n" << endl;

Movie *ptr = db.findMovie_byName("xyz");
ptr->display();   // Dynamic Binding


IMDB *fptr = dynamic_cast<IMDB*>(ptr);
cout << "IMDB Rating:" + fptr->getRating() << endl;   // Dynamic Casting
cout << "Total Votes Received:" + fptr->getVoteCount() << endl; 

/*IMDB m1 = db.findMovie_byName("xyz");
m1.display();*/



}
