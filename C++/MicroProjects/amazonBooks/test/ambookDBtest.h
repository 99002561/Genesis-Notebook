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

    Ambook* b1 = db.findBook_byName("Abc4");
   // b1->display();
    ASSERT_EQ("",b1->getBookPrice());
}

TEST(AmbookDB,listBooks){
    AmbookDB db;
    db.addBook("Abc","Google","Techno","2021","4.5","2000$");
    db.addBook("Abc1","Google","Techno","2021","4.5","2000$");
    db.addBook("Abc2","Google","Techno","2021","4.5","2000$");

    db.importDataset("booksDataset.csv");
    ASSERT_EQ(true,db.listBooks(4));
}



#endif