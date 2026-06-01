#include <gtest/gtest.h>

#include "cigarStringsEasy.h"

TEST(CigarStringsEasyTest, ReturnsTrueForFullMatch) {
    EXPECT_EQ(cigarStringsEasy("5M", "ACTGC"), "True");
}

TEST(CigarStringsEasyTest, ReturnsFalseForPartialMatchWithSoftClipping) {
    EXPECT_EQ(cigarStringsEasy("3M2S", "ACTGC"), "False");
}

TEST(CigarStringsEasyTest, ReturnsInvalidCigarWhenLengthDoesNotMatch) {
    EXPECT_EQ(cigarStringsEasy("4M2S", "ACTGC"), "Invalid cigar");
}
