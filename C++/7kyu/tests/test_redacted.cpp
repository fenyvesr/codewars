#include <gtest/gtest.h>

#include "redacted.h"

struct RedactedTestCase {
    std::string doc1;
    std::string doc2;
    bool expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const RedactedTestCase& tc) {
        return os
            << "{ doc1: \"" << tc.doc1
            << "\", doc2: \"" << tc.doc2
            << "\", expected: " << (tc.expected ? "true" : "false")
            << " }";
    }
};

class RedactedTest :
    public ::testing::TestWithParam<RedactedTestCase> {};

TEST_P(RedactedTest, ReturnsExpectedResult) {
    EXPECT_EQ(
        redacted(GetParam().doc1, GetParam().doc2),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    RedactedTests,
    RedactedTest,
    ::testing::Values(
        // Existing tests
        RedactedTestCase{
            "TOP SECRET:\n"
            "The missile launch code for Sunday XXXXXXXXXX is:\n"
            "XXXXXXXXXXXXXXXXX",
            "TOP SECRET:\n"
            "The missile launch code for Sunday 5th August is:\n"
            "7-ZERO-8X-ALPHA-1",
            true
        },
        RedactedTestCase{
            "The name of the mole is Professor XXXXX",
            "The name of the mole is Professor Dinglemouse",
            false
        },
        RedactedTestCase{
            "XXXXXXXX XXXXXXX XXXXXXXXXXXXXXXXXXX\n"
            "XXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXX XXXXXXXXXXXXX XXXXX",
            "Area-51. Medical Report. 23/Oct/1969\n"
            "E.T. subject 4 was given an aspirin after reporting sick for duty today",
            true
        },

        // Exact match
        RedactedTestCase{"ABC", "ABC", true},

        // X wildcard
        RedactedTestCase{"AXC", "ABC", true},
        RedactedTestCase{"XXX", "ABC", true},
        RedactedTestCase{"X", "A", true},
        RedactedTestCase{"X", "1", true},
        RedactedTestCase{"X", " ", true},

        // Normal mismatch
        RedactedTestCase{"ABC", "ABD", false},

        // Empty strings
        RedactedTestCase{"", "", true},

        // Newlines
        RedactedTestCase{"X\nX", "A\nB", true},
        RedactedTestCase{"X\nX", "AAB", false},

        // Spaces and punctuation
        RedactedTestCase{"XXX-XXX", "ABC-123", true},
        RedactedTestCase{"ABC-XXX", "ABC-123", true},

        // X only works in doc1
        RedactedTestCase{"ABC", "AXC", false}
    )
);

TEST(RedactedEdgeTest, DifferentLengthsFail) {
    EXPECT_FALSE(
        redacted("ABC", "AB")
    );
}

TEST(RedactedEdgeTest, DifferentLengthsFailEvenWithX) {
    EXPECT_FALSE(
        redacted("XXX", "AB")
    );
}
