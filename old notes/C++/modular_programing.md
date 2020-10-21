## 1. Create C++ files (Modular Programming)
    
    1. Create .h file   (Declaration file)

    2. Create .cpp file (Defining File)

        cmd >>> touch sqrt.cpp  
         
            #include <math.h>
            double squareRoot(const double a)  // Get the Square root of a number. 
            {
            double b = sqrt(a);
            if(b != b) // NaN check
             { return -1.0; }
            else
                 { return sqrt(a); }
             }
                
    3. Create test.cpp file (File with Test cases)
    
        cmd >>> touch sqrt_test.cpp

        #include "sqrt.h/.cpp"                    # .h for commands .cpp for make files
        #include <gtest/gtest.h>
        
        TEST(SquareRootTest, PositiveNos) 
        { 
            ASSERT_EQ(6, squareRoot(36.0));
            ASSERT_EQ(18.0, squareRoot(324.0));
            ASSERT_EQ(25.4, squareRoot(645.16));
            ASSERT_EQ(0, squareRoot(0.0));
        }
        
        TEST(SquareRootTest, NegativeNos) 
        {
            ASSERT_EQ(-1.0, squareRoot(-15.0));
            ASSERT_EQ(-1.0, squareRoot(-0.2));
        }
        
        int main(int argc, char **argv) 
        {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }