#include<gtest/gtest.h>
#include"Account.h"
#include"CreditAccount.h"
#include"SavingsAccount.h"
using namespace std;

TEST(CreditAccount,DefaultConstructor) {
    CreditAccount ca1("start","end",1224);
    EXPECT_EQ(1100,ca1.debit(124));
    EXPECT_EQ(1324,ca1.credit(224));
}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
