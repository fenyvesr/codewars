#include <gtest/gtest.h>

#include "subarrayElementsSum.h"

TEST(SubarrayElementsSumTest, BasicCases) {
    EXPECT_EQ(
        subarrayElementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}),
        16
    );

    EXPECT_EQ(
        subarrayElementsSum({{3}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}),
        15
    );

    EXPECT_EQ(
        subarrayElementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}),
        7
    );

    EXPECT_EQ(
        subarrayElementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}, 5),
        12
    );

    EXPECT_EQ(
        subarrayElementsSum({{3, 2}, {4}, {}}),
        0
    );
}
