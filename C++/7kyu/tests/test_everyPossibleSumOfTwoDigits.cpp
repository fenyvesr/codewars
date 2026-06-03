#include <gtest/gtest.h>

#include "everyPossibleSumOfTwoDigits.h"

struct EveryPossibleSumOfTwoDigitsTestCase {
    int input;
    std::vector<int> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const EveryPossibleSumOfTwoDigitsTestCase& tc) {
        os << "{ input: " << tc.input << ", expected: {";
        for (const auto& sum : tc.expected)
            os << sum << ", ";
        return os << "} }";
    }
};

class EveryPossibleSumOfTwoDigitsTest :
    public ::testing::TestWithParam<EveryPossibleSumOfTwoDigitsTestCase> {};

TEST_P(EveryPossibleSumOfTwoDigitsTest, ReturnsExpectedResult) {
    EXPECT_EQ(
        everyPossibleSumOfTwoDigits(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    EveryPossibleSumOfTwoDigitsTests,
    EveryPossibleSumOfTwoDigitsTest,
    ::testing::Values(
        // Existing tests
        EveryPossibleSumOfTwoDigitsTestCase{156, {6, 7, 11}},
        EveryPossibleSumOfTwoDigitsTestCase{81596, {9, 13, 17, 14, 6, 10, 7, 14, 11, 15}},
        EveryPossibleSumOfTwoDigitsTestCase{3852, {11, 8, 5, 13, 10, 7}},
        EveryPossibleSumOfTwoDigitsTestCase{3264128, {5, 9, 7, 4, 5, 11, 8, 6, 3, 4, 10, 10, 7, 8, 14, 5, 6, 12, 3, 9, 10}},
        EveryPossibleSumOfTwoDigitsTestCase{999999, {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18}},

        // Edge cases
        EveryPossibleSumOfTwoDigitsTestCase{0, {}},
        EveryPossibleSumOfTwoDigitsTestCase{5, {}},
        EveryPossibleSumOfTwoDigitsTestCase{10, {1}},
        EveryPossibleSumOfTwoDigitsTestCase{11, {2}},
        EveryPossibleSumOfTwoDigitsTestCase{100, {1, 1, 0}},
        EveryPossibleSumOfTwoDigitsTestCase{101, {1, 2, 1}},
        EveryPossibleSumOfTwoDigitsTestCase{909, {9, 18, 9}},
        EveryPossibleSumOfTwoDigitsTestCase{123, {3, 4, 5}},
        EveryPossibleSumOfTwoDigitsTestCase{1111, {2, 2, 2, 2, 2, 2}},
        EveryPossibleSumOfTwoDigitsTestCase{1000, {1, 1, 1, 0, 0, 0}},

        // Negative cases
        EveryPossibleSumOfTwoDigitsTestCase{-12, {-2, -1, 3}}
    )
);
