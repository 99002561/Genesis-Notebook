#ifndef _ambookTest_h
#define _ambookTest_h

#include <gtest/gtest.h>
#include "../src/Ambook.h"




TEST(Ambook,DefualtConstructor){
    Ambook b1;
    ASSERT_EQ(0,b1.getBookName().length());
    ASSERT_EQ("",b1.getBookPrice());
}


TEST(Ambook,ParametricConstructor){
    Ambook b1("Abc","Google","Techno","2021","4.5","2000$");
    ASSERT_EQ(3,b1.getBookName().length());
    ASSERT_EQ("2000$",b1.getBookPrice());
}




#endif // !1