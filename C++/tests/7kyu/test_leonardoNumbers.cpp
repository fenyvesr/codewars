#include <gtest/gtest.h>

#include "leonardoNumbers.h"

TEST(LeonardoNumbersTest, BasicCases) {
    EXPECT_EQ(leonardoNumbers(5, 1, 1, 1),
              (std::vector<int>{1, 1, 3, 5, 9}));

    EXPECT_EQ(leonardoNumbers(5, 0, 0, 2),
              (std::vector<int>{0, 0, 2, 4, 8}));

    EXPECT_EQ(leonardoNumbers(5, 0, 0, 0),
              (std::vector<int>{0, 0, 0, 0, 0}));
}
