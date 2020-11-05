#include "AmbookDB.h"

void AmbookDB::addBook(string name,string athr,string genre,string year,string rating,string price)
{
    l_books.push_back(Ambook(name,athr,genre,year,rating,price));
}

Ambook* AmbookDB::findbook_byName(string name){

list<Ambook>::iterator iter=l_books.begin();

    while (iter!=l_books.end())
    {
        if(iter->getBookName()== name){
            return &(*iter);
        }
    }
}