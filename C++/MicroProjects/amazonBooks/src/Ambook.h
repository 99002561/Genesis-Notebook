#ifndef _ambook_h
#define _ambook_h

#include "Book.h"

using std::string;

class Ambook:public Book
{
private:
    string b_rating;
    string b_price;
    
public:
    Ambook()=default;
    //Name,Author,Genre,Year,rating,price
    Ambook(string,string,string,string,string,string);

    string getBookRating();
    string getBookPrice();

    void display();


};



#endif // !_ambook_h
