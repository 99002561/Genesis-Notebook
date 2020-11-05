#ifndef _ambookDB_h
#define _ambookDB_h

#include "Ambook.h"
#include <list>

using std::list;
using std::string;


class AmbookDB{
list<Ambook> l_books;

public:

//Name,Author,Genre,Year,rating,price
void addBook(string,string ,string ,string ,string ,string );
//void addBook();

//Feature
Ambook* findbook_byName(string);



};

#endif 