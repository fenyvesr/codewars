#include <gtest/gtest.h>

#include "fixStringCase.h"

TEST(FixStringCaseTest, BasicCases) {
    EXPECT_EQ(fixStringCase("coDe"), "code");
    EXPECT_EQ(fixStringCase("CODe"), "CODE");
    EXPECT_EQ(fixStringCase("COde"), "code");
}
