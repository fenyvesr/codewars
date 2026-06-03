#include <gtest/gtest.h>

#include "sumOfABeach.h"

struct SumOfABeachTestCase {
    std::string input;
    std::ptrdiff_t expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const SumOfABeachTestCase& tc) {
        return os
            << "{ input: \"" << tc.input
            << "\", expected: " << tc.expected
            << " }";
    }
};

class SumOfABeachTest :
    public ::testing::TestWithParam<SumOfABeachTestCase> {};

TEST_P(SumOfABeachTest, CountsWordsCorrectly) {
    EXPECT_EQ(
        sumOfABeach(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    SumOfABeachTests,
    SumOfABeachTest,
    ::testing::Values(
        // Existing tests
        SumOfABeachTestCase{"WAtErSlIde", 1},
        SumOfABeachTestCase{"GolDeNSanDyWateRyBeaChSuNN", 3},
        SumOfABeachTestCase{"gOfIshsunesunFiSh", 4},
        SumOfABeachTestCase{"cItYTowNcARShoW", 0},

        // Single keywords
        SumOfABeachTestCase{"sand", 1},
        SumOfABeachTestCase{"water", 1},
        SumOfABeachTestCase{"fish", 1},
        SumOfABeachTestCase{"sun", 1},

        // Case insensitive
        SumOfABeachTestCase{"SAND", 1},
        SumOfABeachTestCase{"WaTeR", 1},
        SumOfABeachTestCase{"FiSh", 1},
        SumOfABeachTestCase{"SuN", 1},

        // Multiple occurrences
        SumOfABeachTestCase{"sandwatersunfish", 4},
        SumOfABeachTestCase{"sandsandsand", 3},
        SumOfABeachTestCase{"waterwater", 2},

        // Embedded in larger words
        SumOfABeachTestCase{"xxsandyy", 1},
        SumOfABeachTestCase{"abcwaterdef", 1},
        SumOfABeachTestCase{"prefixfishsuffix", 1},

        // Empty string
        SumOfABeachTestCase{"", 0},

        // No matches
        SumOfABeachTestCase{"hello world", 0},

        // Mixed matches
        SumOfABeachTestCase{"sand123water456fish789sun", 4}
    )
);

// std::sregex_iterator finds non-overlapping matches.
TEST(SumOfABeachEdgeTest, OverlappingMatchesAreNotCountedTwice) {
    EXPECT_EQ(
        sumOfABeach("sunsun"),
        2
    );
}

TEST(SumOfABeachEdgeTest, AdjacentMatchesAreCountedSeparately) {
    EXPECT_EQ(
        sumOfABeach("sandwaterfishsun"),
        4
    );
}

// Special regex behavior
TEST(SumOfABeachEdgeTest, PartialKeywordDoesNotMatch) {
    EXPECT_EQ(
        sumOfABeach("san wat fis su"),
        0
    );
}

TEST(SumOfABeachEdgeTest, PunctuationDoesNotMatter) {
    EXPECT_EQ(
        sumOfABeach("sand,water.fish:sun"),
        4
    );
}
