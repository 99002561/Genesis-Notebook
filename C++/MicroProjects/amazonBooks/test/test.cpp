#include "bookTest.h"
#include "ambookTest.h"
#include "ambookDBtest.h"

#define _cmake_ 

#ifdef _cmake_
#include "../src/Book.cpp"
#include "../src/Ambook.cpp"
#include "../src/AmbookDB.cpp"
#endif



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

