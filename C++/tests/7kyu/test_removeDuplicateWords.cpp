#include <gtest/gtest.h>

#include "removeDuplicateWords.h"

TEST(RemoveDuplicateWordsTest, BasicCases) {
    EXPECT_EQ(
        removeDuplicateWords("alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta"),
        "alpha beta gamma delta"
    );

    EXPECT_EQ(
        removeDuplicateWords("my cat is cat fat"),
        "my cat is fat"
    );
}
