#include <gtest/gtest.h>
#include "functions.h"  // Include the header of the class or functions you are testing

// Test case for the add function
TEST(MathTest, HandlesZeroInput) {
    EXPECT_EQ(0, add(0, 0));
}

TEST(MathTest, HandlesPositiveInput) {
    EXPECT_EQ(5, add(2, 3));
}

