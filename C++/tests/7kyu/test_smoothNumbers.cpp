#include <gtest/gtest.h>

#include "smoothNumbers.h"

TEST(SmoothNumbersTest, BasicCases) {
    EXPECT_EQ(smoothNumbers(16),  "power of 2");
    EXPECT_EQ(smoothNumbers(36),  "3-smooth");
    EXPECT_EQ(smoothNumbers(60),  "Hamming number");
    EXPECT_EQ(smoothNumbers(98),  "humble number");
    EXPECT_EQ(smoothNumbers(111), "non-smooth");
}
