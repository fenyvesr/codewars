#include <gtest/gtest.h>

#include "everyPossibleSumOfTwoDigits.h"

TEST(EveryPossibleSumOfTwoDigitsTest, BasicCases) {
    EXPECT_EQ(everyPossibleSumOfTwoDigits(156),
              (std::vector<int>{6, 7, 11}));

    EXPECT_EQ(everyPossibleSumOfTwoDigits(81596),
              (std::vector<int>{9, 13, 17, 14, 6, 10, 7, 14, 11, 15}));

    EXPECT_EQ(everyPossibleSumOfTwoDigits(3852),
              (std::vector<int>{11, 8, 5, 13, 10, 7}));

    EXPECT_EQ(everyPossibleSumOfTwoDigits(3264128),
              (std::vector<int>{5, 9, 7, 4, 5, 11, 8, 6, 3, 4, 10, 10, 7, 8, 14, 5, 6, 12, 3, 9, 10}));

    EXPECT_EQ(everyPossibleSumOfTwoDigits(999999),
              (std::vector<int>{18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18}));
}
