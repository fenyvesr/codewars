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
        // Original/example-style cases
        EveryPossibleSumOfTwoDigitsTestCase{156, {6, 7, 11}},
        EveryPossibleSumOfTwoDigitsTestCase{81596, {9, 13, 17, 14, 6, 10, 7, 14, 11, 15}},
        EveryPossibleSumOfTwoDigitsTestCase{3852, {11, 8, 5, 13, 10, 7}},
        EveryPossibleSumOfTwoDigitsTestCase{3264128, {5, 9, 7, 4, 5, 11, 8, 6, 3, 4, 10, 10, 7, 8, 14, 5, 6, 12, 3, 9, 10}},
        EveryPossibleSumOfTwoDigitsTestCase{999999, {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18}},

        // No pair can be formed
        EveryPossibleSumOfTwoDigitsTestCase{0, {}},
        EveryPossibleSumOfTwoDigitsTestCase{5, {}},
        EveryPossibleSumOfTwoDigitsTestCase{9, {}},

        // Smallest two-digit numbers
        EveryPossibleSumOfTwoDigitsTestCase{10, {1}},
        EveryPossibleSumOfTwoDigitsTestCase{11, {2}},
        EveryPossibleSumOfTwoDigitsTestCase{99, {18}},

        // Zeros inside the number
        EveryPossibleSumOfTwoDigitsTestCase{100, {1, 1, 0}},
        EveryPossibleSumOfTwoDigitsTestCase{101, {1, 2, 1}},
        EveryPossibleSumOfTwoDigitsTestCase{909, {9, 18, 9}},
        EveryPossibleSumOfTwoDigitsTestCase{1000, {1, 1, 1, 0, 0, 0}},
        EveryPossibleSumOfTwoDigitsTestCase{1001, {1, 1, 2, 0, 1, 1}},
        EveryPossibleSumOfTwoDigitsTestCase{9090, {9, 18, 9, 9, 0, 9}},

        // Order-sensitive cases: results follow pair order in the digit string
        EveryPossibleSumOfTwoDigitsTestCase{123, {3, 4, 5}},
        EveryPossibleSumOfTwoDigitsTestCase{321, {5, 4, 3}},
        EveryPossibleSumOfTwoDigitsTestCase{1234, {3, 4, 5, 5, 6, 7}},
        EveryPossibleSumOfTwoDigitsTestCase{4321, {7, 6, 5, 5, 4, 3}},

        // Repeated digits
        EveryPossibleSumOfTwoDigitsTestCase{1111, {2, 2, 2, 2, 2, 2}},
        EveryPossibleSumOfTwoDigitsTestCase{22222, {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}},
        EveryPossibleSumOfTwoDigitsTestCase{55555, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}},

        // Mixed larger inputs
        EveryPossibleSumOfTwoDigitsTestCase{10203, {1, 3, 1, 4, 2, 0, 3, 2, 5, 3}},
        EveryPossibleSumOfTwoDigitsTestCase{987654321, {17, 16, 15, 14, 13, 12, 11, 10, 15, 14, 13, 12, 11, 10, 9, 13, 12, 11, 10, 9, 8, 11, 10, 9, 8, 7, 9, 8, 7, 6, 7, 6, 5, 5, 4, 3}},

        // Current implementation treats '-' from std::to_string as a character.
        // These cases document that behavior rather than the likely Codewars domain.
        EveryPossibleSumOfTwoDigitsTestCase{-1, {-2}},
        EveryPossibleSumOfTwoDigitsTestCase{-12, {-2, -1, 3}},
        EveryPossibleSumOfTwoDigitsTestCase{-101, {-2, -3, -2, 1, 2, 1}}
    )
);
