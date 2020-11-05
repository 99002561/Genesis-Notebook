#include "Book.h"

Book::Book(string name,string authr,string genre,string yr):
    b_name(name),
    b_author(authr),
    b_genre(genre),
    b_year(yr)
    {}

string Book::getBookName(){
return b_name;
}
string Book::getBookAuthor(){
return b_author;
}
string Book::getBookGenre(){
return b_genre;
}
string Book::getBookYear(){
return b_year;
}

void Book::display(){
    print("Name: "+b_name);
   print("Author: "+b_author);
   print("Genre: "+b_genre);
   print("Year: "+b_year);

}