#include <gtest/gtest.h>

#include "convertTheScore.h"

struct TestCase {
    std::string input;
    std::vector<int> expected;
};

class ConvertTheScoreTest :
    public ::testing::TestWithParam<TestCase> {};

TEST_P(ConvertTheScoreTest, ConvertsCorrectly) {
    EXPECT_EQ(convertTheScore(GetParam().input),
              GetParam().expected);
}

INSTANTIATE_TEST_SUITE_P(
    ConvertTheScoreTests,
    ConvertTheScoreTest,
    ::testing::Values(
        TestCase{"The score is four nil", {4, 0}},
        TestCase{"new score: two three", {2, 3}},
        TestCase{"two two", {2, 2}},
        TestCase{"Arsenal just conceded another goal, two nil", {2, 0}}
    )
);
