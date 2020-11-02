
//#define _gtest_
//#define _cmake_

#ifdef _cmake_
#include "imdb.cpp"
#include "imdbDB.cpp"
#include "movies.cpp"
#endif


#ifdef _gtest_
#include "imdbTest.h"
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else   

#include "testDB.h"
int main(){
    dataBase_test();
    return 0;
}

#endif


