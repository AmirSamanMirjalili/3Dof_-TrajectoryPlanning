#include <iostream>
#include "functions.h"
#include <gtest/gtest.h>


 TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(2, add(1, 1));
}

int main(int argc, char **argv) {

    //Run Test
    std::cout << "Running tests..." << std::endl;

    // Create instances of other classes and test their methods
    ::testing::InitGoogleTest(&argc, argv);
     // Add more tests here

    return RUN_ALL_TESTS();
}

   
