#include<gtest/gtest.h>
#include"Employee.h"
#include"Manager.h"
#include"Trainee.h"
#include"Employee.h"
#include"Engineer.h"

TEST(Engineer,Test1)
{
    Engineer e1("engg","Niranjan", 2516, 161, 39);
    e1.appraisal(500);
    EXPECT_EQ(3016,e1.payroll());
}

