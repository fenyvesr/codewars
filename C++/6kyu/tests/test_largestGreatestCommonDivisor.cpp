#include <gtest/gtest.h>

#include "largestGreatestCommonDivisor.h"

struct LargestGreatestCommonDivisorTestCase {
    long long a;
    long long b;
    long long expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const LargestGreatestCommonDivisorTestCase& tc) {
        os  << "{ a: " << tc.a
            << ", b: " << tc.b
            << ", expected: " << tc.expected << " }";
        return os;
    }
};

class LargestGreatestCommonDivisorTest :
    public ::testing::TestWithParam<LargestGreatestCommonDivisorTestCase> {};

TEST_P(LargestGreatestCommonDivisorTest, ReturnsExpectedValue) {
    EXPECT_EQ(
        get_k(GetParam().a, GetParam().b),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    LargestGreatestCommonDivisorTests,
    LargestGreatestCommonDivisorTest,
    ::testing::Values(
        // Test cases where k is found to maximize gcd(a+k, b+k)
        LargestGreatestCommonDivisorTestCase{5, 7, 1},
        LargestGreatestCommonDivisorTestCase{2, 10, 6},
        LargestGreatestCommonDivisorTestCase{100, 200, 100},
        LargestGreatestCommonDivisorTestCase{123, 456, 210},
        LargestGreatestCommonDivisorTestCase{12, 18, 6},
        LargestGreatestCommonDivisorTestCase{1, 2, 1},
        LargestGreatestCommonDivisorTestCase{2, 4, 2},
        LargestGreatestCommonDivisorTestCase{10, 15, 5},
        LargestGreatestCommonDivisorTestCase{8, 12, 4}
    )
);
