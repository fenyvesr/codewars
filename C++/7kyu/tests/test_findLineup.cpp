#include <gtest/gtest.h>

#include "findLineup.h"

struct FindLineupTestCase {
    std::vector<std::size_t> input;
    std::vector<std::size_t> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const FindLineupTestCase& tc) {
        os << "{ input: {";
        for (auto val : tc.input)
            os << val << ", ";
        os << "}, expected: {";
        for (auto val : tc.expected)
            os << val << ", ";
        return os << "} }";
    }
};


class FindLineupTest :
    public ::testing::TestWithParam<FindLineupTestCase> {};

TEST_P(FindLineupTest, ReturnsExpectedSequence) {
    EXPECT_EQ(
        find_lineup(
            GetParam().input
        ),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    FindLineupTests,
    FindLineupTest,
    ::testing::Values(
        // Existing / kata-like examples
        FindLineupTestCase{{ 1, 2, 0 }, { 3, 1, 2 }},
        FindLineupTestCase{{ 1, 4, 2, 6, 8, 0, 5, 7, 3 }, { 6, 1, 3, 9, 2, 7, 4, 8, 5 }},
        FindLineupTestCase{{ 0 }, { 1 }},
        FindLineupTestCase{{ 1 }, { }},
        FindLineupTestCase{{ 1, 0, 1 }, { }},
        FindLineupTestCase{{ 1, 2, 0, 4 }, { }},
        FindLineupTestCase{{2, 6, 4}, { }},
        FindLineupTestCase{{65, 60, 21, 56, 54, 4, 47, 30, 42, 50, 9, 10, 46, 27, 28, 63, 52, 58, 32, 33, 38, 68, 107, 45, 55, 35, 25, 66, 11, 59, 34, 62, 61, 37, 15, 26, 49, 48, 16, 64, 43, 17, 41, 14, 3, 7, 2, 20, 51, 1, 44, 12, 18, 0, 19, 23, 24, 31, 40, 5, 67, 57, 36, 39, 8, 6, 13, 29, 22}, { }}
    )
);

