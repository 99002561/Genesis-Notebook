#ifndef book_h
#define book_h

#include <string>
#include <iostream>
#define print(msg) std::cout << msg << std::endl

using std::string;

class Book
{
protected:
    string b_name;
    string b_author;
    string b_genre;
    string b_year;

public:
    Book()=default;
    //Name,Author,Genre,Year
    Book(string,string,string,string);

    string getBookName();
    string getBookAuthor();
    string getBookGenre();
    string getBookYear();

    virtual void display();
    
};






#endif // !book_h