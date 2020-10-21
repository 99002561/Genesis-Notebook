#include "imdbDB.h"
#include <iterator>


void IMDBdatabase::addMovie(string mtitle,string mCrtor,string mCntry,string mYear,string mGen,string rat,string VtCnt){

    l_movies.push_back(IMDB(mtitle,mCrtor,mCntry,mYear,mGen,rat,VtCnt));
}

void IMDBdatabase::addMovie(IMDB i_mov){

    l_movies.push_back(i_mov);
}

void IMDBdatabase::addMovie(vector<string> data){
    l_movies.push_back(IMDB(data[0],data[1],data[2],data[3],data[4],data[5],data[6]));
}


IMDB* IMDBdatabase::findMovie_byName(string title){

list<IMDB>::iterator iter;

    for(iter = l_movies.begin();iter != l_movies.end();iter++)
    {
        if(title == iter->getTitle())
        {
            return &(*iter);
        }
        
    }
    return (&nullObj);
}

/*
IMDB IMDBdatabase::findMovie_byName(string title){

list<IMDB>::iterator iter;
IMDB nullOBj;

    for(iter = l_movies.begin();iter != l_movies.end();iter++)
    {
        if(title == iter->getTitle())
        {
            return (*iter);
        }
        
    }
    return nullOBj;
}
*/

void IMDBdatabase::showMovies_byRating(string rat){

list<IMDB>::iterator iter;
    for(iter = l_movies.begin();iter != l_movies.end();iter++)
    {
        if(iter->getRating() >= rat)
        {
          //  cout << "Found" << endl;
            cout << iter->getTitle() << endl;
        }
        
    }

}



void IMDBdatabase::importDataset(string fileName){

ifstream file;  // define file handler in readmode
string line,dataField;

file.open(fileName);

getline(file,line);  //Read 1st line
vector<string> lineData;

    while(getline(file,line)){     //Read from 2nd Line
        stringstream s(line);  // Converting datatype
        while (getline(s, dataField,',')) {     //extract dataFiled into vector
        lineData.push_back(dataField);
        }
        addMovie(lineData);
        lineData.clear();

    }

file.close();

}//Import end

