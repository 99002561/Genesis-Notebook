#ifndef _ambookDBTest_h
#define _ambookDBTest_h

#include <iostream>

#include "../src/AmbookDB.h"
#include <gtest/gtest.h>

TEST(AmbookDB,findBook_byname){
    AmbookDB db;
    db.addBook("Abc","Google","Techno","2021","4.5","2000$");
    db.addBook("Abc1","Google","Techno","2021","4.5","2000$");
    db.addBook("Abc2","Google","Techno","2021","4.5","2000$");

    Ambook* b1 = db.findbook_byName("Abc");
    b1->display();
    ASSERT_EQ("2000$",b1->getBookPrice());

}



#endif