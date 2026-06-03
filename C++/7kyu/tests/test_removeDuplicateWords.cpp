#include <gtest/gtest.h>

#include "removeDuplicateWords.h"

struct RemoveDuplicateWordsTestCase {
    std::string input;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const RemoveDuplicateWordsTestCase& tc) {
        return os
            << "{ input: \"" << tc.input
            << "\", expected: \"" << tc.expected
            << "\" }";
    }
};

class RemoveDuplicateWordsTest :
    public ::testing::TestWithParam<RemoveDuplicateWordsTestCase> {};

TEST_P(RemoveDuplicateWordsTest, RemovesDuplicatesCorrectly) {
    EXPECT_EQ(
        removeDuplicateWords(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    RemoveDuplicateWordsTests,
    RemoveDuplicateWordsTest,
    ::testing::Values(
        // Existing tests
        RemoveDuplicateWordsTestCase{
            "alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta",
            "alpha beta gamma delta"
        },
        RemoveDuplicateWordsTestCase{
            "my cat is cat fat",
            "my cat is fat"
        },

        // Empty input
        RemoveDuplicateWordsTestCase{"", ""},

        // Single word
        RemoveDuplicateWordsTestCase{"hello", "hello"},

        // All duplicates
        RemoveDuplicateWordsTestCase{"a a a a a", "a"},

        // No duplicates
        RemoveDuplicateWordsTestCase{"a b c d", "a b c d"},

        // Duplicate at end
        RemoveDuplicateWordsTestCase{"a b c a", "a b c"},

        // Duplicate at beginning
        RemoveDuplicateWordsTestCase{"a a b c", "a b c"},

        // Case-sensitive
        RemoveDuplicateWordsTestCase{"Word word WORD", "Word word WORD"},

        // Numbers
        RemoveDuplicateWordsTestCase{"1 2 2 3 1", "1 2 3"},

        // Punctuation considered part of word
        RemoveDuplicateWordsTestCase{"hello hello, hello", "hello hello,"},

        // Tabs and multiple spaces
        RemoveDuplicateWordsTestCase{"a\tb\tb\tc", "a b c"},
        RemoveDuplicateWordsTestCase{"a    b    b    c", "a b c"},

        // Leading/trailing spaces
        RemoveDuplicateWordsTestCase{"   a b c   ", "a b c"},

        // Mixed whitespace
        RemoveDuplicateWordsTestCase{"a\nb\nb\nc", "a b c"}
    )
);

TEST(RemoveDuplicateWordsEdgeTest, PreservesFirstOccurrence) {
    EXPECT_EQ(
        removeDuplicateWords("c b a c b a"),
        "c b a"
    );
}

TEST(RemoveDuplicateWordsEdgeTest, IsCaseSensitive) {
    EXPECT_EQ(
        removeDuplicateWords("Dog dog DOG Dog"),
        "Dog dog DOG"
    );
}

TEST(RemoveDuplicateWordsEdgeTest, TreatsPunctuationAsPartOfWord) {
    EXPECT_EQ(
        removeDuplicateWords("hello hello, hello."),
        "hello hello, hello."
    );
}
