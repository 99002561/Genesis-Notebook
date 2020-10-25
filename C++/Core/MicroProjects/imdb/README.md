
# Design
* Base class Movies
    * Data Membes :
        -   Title
        -   Creators
        -   Country   
        -   Year
        -   Genre
    

    * Derived Class IMDB
        * Data Members
            - rating
            - totalVotes
`

# Commands

g++ test.cpp imdb.cpp movies.cpp -c
g++ test.o imdb.o movies.o -lgtest -lgtest_main -lpthread -o out
./out

g++ testDB.cpp imdbDB.cpp imdb.cpp movies.cpp -c
g++ testDB.o imdbDB.o imdb.o movies.o -o out
g++ testDB.cpp imdbDB.cpp imdb.cpp movies.cpp -o out


# 

cd build
cmake .
make
./out