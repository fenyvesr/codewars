#include <gtest/gtest.h>

#include "tramCapacity.h"

TEST(TramCapacityTest, BasicCases) {
    EXPECT_EQ(tramCapacity(4,  {0, 2, 4, 4},                   {3, 5, 2, 0}),                   6);
    EXPECT_EQ(tramCapacity(2,  {0, 2, 4, 4},                   {3, 5, 2, 0}),                   6);
    EXPECT_EQ(tramCapacity(1,  {0, 2, 4, 4},                   {3, 5, 2, 0}),                   3);
    EXPECT_EQ(tramCapacity(10, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 25);
    EXPECT_EQ(tramCapacity(5,  {0, 2, 4, 14, 2},               {3, 5, 14, 0, 0}),               16);
}
