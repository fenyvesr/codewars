#include <gtest/gtest.h>

#include "fixStringCase.h"

struct FixStringTestCase {
    std::string input;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const FixStringTestCase& tc) {
        return os
            << "{ input: \"" << tc.input
            << "\", expected: \"" << tc.expected
            << "\" }";
    }
};

class FixStringCaseTest :
    public ::testing::TestWithParam<FixStringTestCase> {};

TEST_P(FixStringCaseTest, ReturnsExpectedResult) {
    EXPECT_EQ(
        fixStringCase(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    FixStringCaseTests,
    FixStringCaseTest,
    ::testing::Values(
        // Existing tests
        FixStringTestCase{"coDe", "code"},
        FixStringTestCase{"CODe", "CODE"},
        FixStringTestCase{"COde", "code"},

        // Single characters
        FixStringTestCase{"a", "a"},
        FixStringTestCase{"A", "A"},

        // All lower
        FixStringTestCase{"code", "code"},

        // All upper
        FixStringTestCase{"CODE", "CODE"},

        // Tie -> lowercase
        FixStringTestCase{"cO", "co"},
        FixStringTestCase{"AbCd", "abcd"},
        FixStringTestCase{"ABcd", "abcd"},

        // Majority uppercase
        FixStringTestCase{"ABCd", "ABCD"},
        FixStringTestCase{"ABCDx", "ABCDX"},

        // Majority lowercase
        FixStringTestCase{"abCDx", "abcdx"},

        // Empty string
        FixStringTestCase{"", ""},

        // Non-letters preserved by case conversion
        FixStringTestCase{"ab12CD", "ab12cd"},
        FixStringTestCase{"ABC123d", "abc123d"},

        // Symbols
        FixStringTestCase{"A!B?", "a!b?"},
        FixStringTestCase{"a!B?", "a!b?"}
    )
);

