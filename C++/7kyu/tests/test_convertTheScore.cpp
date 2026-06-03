#include <gtest/gtest.h>

#include "convertTheScore.h"

struct ConvertTheScoreTestCase {
    std::string input;
    std::vector<int> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const ConvertTheScoreTestCase& tc) {
        os << "{ input: \"" << tc.input
            << "\", expected: {";
        for(const auto& element : tc.expected)
            os << element << ", ";
        return os << "} }";
    }
};

class ConvertTheScoreTest :
    public ::testing::TestWithParam<ConvertTheScoreTestCase> {};

TEST_P(ConvertTheScoreTest, ConvertsCorrectly) {
    EXPECT_EQ(convertTheScore(GetParam().input),
              GetParam().expected);
}

INSTANTIATE_TEST_CASE_P(
    ConvertTheScoreTests,
    ConvertTheScoreTest,
    ::testing::Values(
        ConvertTheScoreTestCase{"The score is four nil", {4, 0}},
        ConvertTheScoreTestCase{"new score: two three", {2, 3}},
        ConvertTheScoreTestCase{"two two", {2, 2}},
        ConvertTheScoreTestCase{"Arsenal just conceded another goal, two nil", {2, 0}},
        ConvertTheScoreTestCase{"one two three", {1, 3}},
        ConvertTheScoreTestCase{"score one, then lots of text, and nine", {1, 9}},
        ConvertTheScoreTestCase{"zero is not valid, but one two is", {1, 2}},
        ConvertTheScoreTestCase{"nil nil", {0, 0}},
        ConvertTheScoreTestCase{"nine eight", {9, 8}}
    )
);

TEST(ConvertTheScoreEdgeTest, ThrowsWhenNoScoreWordsFound) {
    EXPECT_THROW(convertTheScore("the score is zero ten"), std::out_of_range);
}

TEST(ConvertTheScoreEdgeTest, ThrowsWhenOnlyOneScoreWordFound) {
    EXPECT_THROW(convertTheScore("the score is five"), std::out_of_range);
}
