#include "Ambook.h"
#include <iostream>
#define print(msg) std::cout << msg << std::endl



Ambook::Ambook(string name,string athr,string genre,string year,string rating,string price):
Book(name,athr,genre,year),
b_rating(rating),
b_price(price)
{}


string Ambook::getBookRating(){
    return b_rating;
}
string Ambook::getBookPrice(){
    return b_price;
}

void Ambook::display(){
   print("Name: "+b_name);
   print("Author: "+b_author);
   print("Genre: "+b_genre);
   print("Year: "+b_year);
   print("Rating: "+b_rating);
   print("Price: "+b_price);
}
