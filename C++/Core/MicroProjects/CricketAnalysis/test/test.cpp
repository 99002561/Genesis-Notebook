#include "../src/player.h"
#include "../src/cricket.h"
#include "../src/cricketDB.h"
#include <gtest/gtest.h>


#define _cmake_
//#define _command_

#ifdef _cmake_
#include "../src/player.cpp"
#include "../src/cricket.cpp"
#include "../src/cricketDB.cpp"
#endif



// Player Class test cases
TEST(player,DefaultConstructor){
player p1;
EXPECT_EQ("",p1.getPlayerName());
}


TEST(player,ParamertricConstructor){
player p1("Mr.Abc","25/12/2020","Karnataka");
EXPECT_EQ("Mr.Abc",p1.getPlayerName());
EXPECT_EQ("25/12/2020",p1.getPlayerDob());
EXPECT_EQ("Karnataka",p1.getPlayerPlace());
}

TEST(cricket,DefaultConstructor){
cricket c1;
EXPECT_EQ("",c1.getPlayerName());
EXPECT_EQ("",c1.getPlayerClass());
}


TEST(cricket,ParamertricConstructor){
cricket c1("Mr.Abc","25/12/2020","Karnataka","Class-I","Batsmen","132");
EXPECT_EQ("Mr.Abc",c1.getPlayerName());
EXPECT_EQ("25/12/2020",c1.getPlayerDob());
EXPECT_EQ("Karnataka",c1.getPlayerPlace());

EXPECT_EQ("Class-I",c1.getPlayerClass());
EXPECT_EQ("Batsmen",c1.getPlayerRole());
EXPECT_EQ("132",c1.getPlayerOdiCount());


}


TEST(playerBase,importDataset){
   playerBase db1;

   db1.importDataset("odi-cricketers.csv") ;
   EXPECT_EQ((cricket*)NULL,db1.getPlayerRecords("Mr.abc"));

    

    cricket* p1 = db1.getPlayerRecords("Shikhar Dhawan");
    EXPECT_EQ("136",p1->getPlayerOdiCount());
}


int main(int argc, char **argv) {
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
    

