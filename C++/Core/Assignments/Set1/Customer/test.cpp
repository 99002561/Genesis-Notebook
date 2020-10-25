#include "pch.h"

TEST(customer, ParameterizedConstructor) {
    customer a1(1001, "Lippman", 5000.0);
    EXPECT_EQ(5000, a1.getbalance());
}