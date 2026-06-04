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
        // Original examples
        FixStringTestCase{"coDe", "code"},
        FixStringTestCase{"CODe", "CODE"},
        FixStringTestCase{"COde", "code"},

        // Empty and single-character inputs
        FixStringTestCase{"", ""},
        FixStringTestCase{"a", "a"},
        FixStringTestCase{"A", "A"},
        FixStringTestCase{"z", "z"},
        FixStringTestCase{"Z", "Z"},

        // Already uniform case
        FixStringTestCase{"code", "code"},
        FixStringTestCase{"CODE", "CODE"},
        FixStringTestCase{"lowercase", "lowercase"},
        FixStringTestCase{"UPPERCASE", "UPPERCASE"},

        // Tie: should choose lowercase
        FixStringTestCase{"cO", "co"},
        FixStringTestCase{"AbCd", "abcd"},
        FixStringTestCase{"ABcd", "abcd"},
        FixStringTestCase{"aBcD", "abcd"},
        FixStringTestCase{"Aa", "aa"},

        // Majority lowercase
        FixStringTestCase{"abCDx", "abcdx"},
        FixStringTestCase{"aBCde", "abcde"},
        FixStringTestCase{"abcD", "abcd"},
        FixStringTestCase{"abcDE", "abcde"},

        // Majority uppercase
        FixStringTestCase{"ABCd", "ABCD"},
        FixStringTestCase{"ABCDx", "ABCDX"},
        FixStringTestCase{"ABcDE", "ABCDE"},
        FixStringTestCase{"aBCDE", "ABCDE"},

        // Non-letter characters are preserved by toupper/tolower,
        // but they still contribute to str.size() in the majority decision.
        FixStringTestCase{"ab12CD", "ab12cd"},     // 2 upper of 6 -> lowercase
        FixStringTestCase{"ABC123d", "abc123d"},   // 3 upper of 7 -> lowercase
        FixStringTestCase{"ABC!d", "ABC!D"},      // 3 upper of 5 -> uppercase
        FixStringTestCase{"AB!cd", "ab!cd"},      // 2 upper of 5 -> lowercase
        FixStringTestCase{"A!B?", "a!b?"},        // 2 upper of 4 -> tie -> lowercase
        FixStringTestCase{"AB!?", "ab!?"},        // 2 upper of 4 -> tie -> lowercase
        FixStringTestCase{"ABC!?", "ABC!?"},      // 3 upper of 5 -> uppercase

        // Digits, punctuation, whitespace only: no uppercase majority,
        // so the lowercase branch is selected and content remains unchanged.
        FixStringTestCase{"12345", "12345"},
        FixStringTestCase{"!!!", "!!!"},
        FixStringTestCase{"   ", "   "},
        FixStringTestCase{"1 2 3", "1 2 3"},

        // Mixed text with spaces/punctuation
        FixStringTestCase{"Hello WORLD!", "hello world!"},
        FixStringTestCase{"HELLO world!", "hello world!"},
        FixStringTestCase{"HELLO WORLD!", "HELLO WORLD!"},
        FixStringTestCase{"Hi THERE", "HI THERE"},
        FixStringTestCase{"HI THERE", "HI THERE"}
    )
);
