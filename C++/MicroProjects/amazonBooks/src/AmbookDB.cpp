#include "AmbookDB.h"

void AmbookDB::addBook(string name,string athr,string genre,string year,string rating,string price)
{
    l_books.push_back(Ambook(name,athr,genre,year,rating,price));
}

Ambook* AmbookDB::findBook_byName(string name){

list<Ambook>::iterator iter;


    for(iter=l_books.begin();iter!=l_books.end();++iter)
    {
        if(iter->getBookName()== name){
            return &(*iter);
        }
    }
    return (&nullBook);
}


void AmbookDB::addBook(vector<string> data){
l_books.push_back(Ambook(data[0],data[1],data[2],data[3],data[4],data[5]));
}

void AmbookDB::importDataset(string fileName){

std::ifstream file;         // define file handler in readmode
string line,dataField;

file.open(fileName);

getline(file,line);  //Read 1st line
vector<string> lineData;

    while(getline(file,line)){     //Read from 2nd Line
        std::stringstream s(line);  // Converting datatype
        while (getline(s, dataField,',')) {     //extract dataFiled into vector
        lineData.push_back(dataField);
        }
        addBook(lineData);
        lineData.clear();
    }

file.close();

}//Import end


bool AmbookDB::listBooks(int rat){
   bool flag = false;

list<Ambook>::iterator iter;
    for(iter=l_books.begin();iter!=l_books.end();++iter)
    {
        if(stoi(iter->getBookRating()) >= rat){
        print("Name: "+iter->getBookName());
        flag = true;
        }
    }
    return flag;
}