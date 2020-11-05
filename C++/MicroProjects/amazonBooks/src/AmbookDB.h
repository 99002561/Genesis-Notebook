#ifndef _ambookDB_h
#define _ambookDB_h

#include "Ambook.h"
#include <list>

#include <bits/stdc++.h> 
#include <vector>
#include <fstream>

using std::list;
using std::string;
using std::vector;
//using 


class AmbookDB{
list<Ambook> l_books;
Ambook nullBook;

public:

//Name,Author,Genre,Year,rating,price
void addBook(string,string ,string ,string ,string ,string );
void addBook(vector<string> data);
//void addBook();

//Feature
Ambook* findBook_byName(string);

//fileName
void importDataset(string);

bool listBooks(int); //rating


};

#endif 