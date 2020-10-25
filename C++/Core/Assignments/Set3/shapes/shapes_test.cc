#include "shape.h"
#include "polygon.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

#include "gtest/gtest.h"

namespace

{
    TEST(Circle, Area)
    {
        Circle c(5);
        double area = c.area();
        EXPECT_FLOAT_EQ(78.5714,area);
    }
    TEST(Circle, Circum)
    {
        Circle c(5);
        EXPECT_FLOAT_EQ(31.428572,c.circumference());
    }

    TEST(Traiangle, Area)
    {
        Triangle t(3,5,6);
        EXPECT_FLOAT_EQ(7.483315,t.area());
    }
     TEST(Traiangle, Circum)
    {
        Triangle t(3,5,6);
        EXPECT_FLOAT_EQ(14,t.circumference());
    }

    TEST(Rectangle, Area)
    {
        Rectangle r(3,5);
        EXPECT_FLOAT_EQ(15,r.area());
    }
    TEST(Rectangle, Circumf)
    {
        Rectangle r(3,5);
        EXPECT_FLOAT_EQ(16,r.circumference());
    }

}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
