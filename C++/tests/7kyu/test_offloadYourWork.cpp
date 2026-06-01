#include <gtest/gtest.h>

#include "offloadYourWork.h"

TEST(OffloadYourWorkTest, BasicCases) {
    EXPECT_EQ(offloadYourWork(60, {{1, 0}}),
              "Easy Money!");

    EXPECT_EQ(offloadYourWork(60, {{0, 0}}),
              "I need to work 1 hour(s) and 0 minute(s)");

    EXPECT_EQ(offloadYourWork(141, {{1, 55}, {0, 25}}),
              "I need to work 0 hour(s) and 1 minute(s)");
}