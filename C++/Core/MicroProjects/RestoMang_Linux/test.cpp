
// billing Test
#include "bill.h"
#include "restaurant.h"
#include "customer_order.h"

#include "bill.cpp"
#include "restaurant.cpp"
#include "customer_order.cpp"

#include <gtest/gtest.h>

namespace {

class BillTest : public ::testing::Test {

protected:
  void SetUp() {
    res.addOrder(9642297555,"Jalsa","Banashankari","yes",101,1,"Bangalore",1500);
    res.addOrder(9642123495,"Onesta","Church Street","yes",102,3,"Bangalore",3500);
    res.addOrder(8762231535,"Om made cafe","Kormangala","no",103,2,"Bangalore",1950);
    res.addOrder(9257614892,"Rasta Cafe","Jalahalli","no",104,1,"Hampi",500);
    res.addOrder(9642291234,"The Vintage Cafe","Mysore Rd","no",105,2,"Mysore",3500);
    res.addOrder(9613986355,"Simon","Kengeri","no",101,4,"Hubli",4000);
    res.addOrder(9642478315,"The Coffee Shack","MG Road","yes",106,3,"Bangalore",2870);
    res.addOrder(9645346785,"Lassi Shop","BTM Layout","yes",109,1,"Bangalore",300);

  }
  void TearDown() {}
  Bill res;
};

TEST_F(BillTest, AddOrder) {
  res.addOrder(9642123495,"Onesta","Church Street","yes",102,3,"Bangalore",3500);
  EXPECT_NE((Restaurant*)NULL, res.findOrderById(102));
  EXPECT_EQ(9, res.countAll());
}

TEST_F(BillTest, RemoveOrder) {
  res.removeOrder(106);
  EXPECT_EQ(NULL, res.findOrderById(106));
  EXPECT_EQ(7, res.countAll());
}

TEST_F(BillTest, CountTest) {             //Just After Setup
  EXPECT_EQ(8, res.countAll());
}

TEST_F(BillTest, AnotherTest) {         //Just After Setup
  res.addOrder(9645444785,"Shack Shop","HSR Layout","yes",110,1,"Bangalore",500);
  /*int count = res.countOrder("110"); */
  EXPECT_EQ(9, res.countAll());
 /* EXPECT_EQ(110, count);  */

}
} // namespace

int main(int argc,char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}



