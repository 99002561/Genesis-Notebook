#ifndef _bookTest_h
#define _bookTest_h

#include <gtest/gtest.h>
#include "../src/Book.h"




TEST(Book,DefualtConstructor){
    Book b1;
    ASSERT_EQ(0,b1.getBookName().length());
    ASSERT_EQ("",b1.getBookName());
}


TEST(Book,ParametricConstructor){
    Book b1("Abc","Google","Techno","2021");
    ASSERT_EQ(3,b1.getBookName().length());
}




#endif // !1