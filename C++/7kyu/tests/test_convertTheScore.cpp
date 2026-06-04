#include <gtest/gtest.h>

#include "convertTheScore.h"

#include <ostream>
#include <string>
#include <vector>

struct ConvertTheScoreTestCase {
    std::string input;
    std::vector<int> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const ConvertTheScoreTestCase& tc) {
        os << "{ input: \"" << tc.input
           << "\", expected: {";
        for (const auto& element : tc.expected) {
            os << element << ", ";
        }
        return os << "} }";
    }
};

class ConvertTheScoreTest :
    public ::testing::TestWithParam<ConvertTheScoreTestCase> {};

TEST_P(ConvertTheScoreTest, ConvertsCorrectly) {
    EXPECT_EQ(convertTheScore(GetParam().input), GetParam().expected);
}

INSTANTIATE_TEST_CASE_P(
    ConvertTheScoreTests,
    ConvertTheScoreTest,
    ::testing::Values(
        // Original/basic examples
        ConvertTheScoreTestCase{"The score is four nil", {4, 0}},
        ConvertTheScoreTestCase{"new score: two three", {2, 3}},
        ConvertTheScoreTestCase{"two two", {2, 2}},
        ConvertTheScoreTestCase{"Arsenal just conceded another goal, two nil", {2, 0}},

        // All supported score words should be convertible.
        ConvertTheScoreTestCase{"nil one", {0, 1}},
        ConvertTheScoreTestCase{"one two", {1, 2}},
        ConvertTheScoreTestCase{"two three", {2, 3}},
        ConvertTheScoreTestCase{"three four", {3, 4}},
        ConvertTheScoreTestCase{"four five", {4, 5}},
        ConvertTheScoreTestCase{"five six", {5, 6}},
        ConvertTheScoreTestCase{"six seven", {6, 7}},
        ConvertTheScoreTestCase{"seven eight", {7, 8}},
        ConvertTheScoreTestCase{"eight nine", {8, 9}},
        ConvertTheScoreTestCase{"nine nil", {9, 0}},

        // Same score twice, including lower and upper valid values.
        ConvertTheScoreTestCase{"nil nil", {0, 0}},
        ConvertTheScoreTestCase{"nine nine", {9, 9}},

        // Words can be embedded in a longer sentence.
        ConvertTheScoreTestCase{"score one, then lots of text, and nine", {1, 9}},
        ConvertTheScoreTestCase{"zero is not valid, but one two is", {1, 2}},
        ConvertTheScoreTestCase{"Kickoff: five goals for them, six for us", {5, 6}},

        // The implementation uses a greedy .* between the two capture groups:
        // with more than two score words, it returns the first and the last.
        ConvertTheScoreTestCase{"one two three", {1, 3}},
        ConvertTheScoreTestCase{"nil one two three four five six seven eight nine", {0, 9}},

        // The regex is not word-boundary protected, so score words inside
        // larger words can also be matched. These tests document current behavior.
        ConvertTheScoreTestCase{"someone scored alone", {1, 1}}
    )
);

TEST(ConvertTheScoreEdgeTest, ThrowsWhenNoScoreWordsFound) {
    EXPECT_THROW(convertTheScore("the score is zero ten"), std::out_of_range);
}

TEST(ConvertTheScoreEdgeTest, ThrowsWhenInputIsEmpty) {
    EXPECT_THROW(convertTheScore(""), std::out_of_range);
}

TEST(ConvertTheScoreEdgeTest, ThrowsWhenOnlyOneScoreWordFound) {
    EXPECT_THROW(convertTheScore("the score is five"), std::out_of_range);
}

TEST(ConvertTheScoreEdgeTest, ThrowsWhenOnlyOneEmbeddedScoreWordFound) {
    EXPECT_THROW(convertTheScore("stone"), std::out_of_range);
}

TEST(ConvertTheScoreEdgeTest, ThrowsWhenOnlyUnsupportedNumericWordsArePresent) {
    EXPECT_THROW(convertTheScore("zero ten"), std::out_of_range);
}
