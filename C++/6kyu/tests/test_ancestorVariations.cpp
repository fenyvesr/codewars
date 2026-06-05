#include <gtest/gtest.h>

#include "ancestorVariations.h"

struct AncestorVariationsTestCase {
    long long n;
    long long expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const AncestorVariationsTestCase& tc) {
        os  << "{ n: " << tc.n
            << ", expected: " << tc.expected << " }";
        return os;
    }
};

class AncestorVariationsTest :
    public ::testing::TestWithParam<AncestorVariationsTestCase> {};

TEST_P(AncestorVariationsTest, ReturnsExpectedValue) {
    EXPECT_EQ(
        ancestor_variations(GetParam().n),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    AncestorVariationsTests,
    AncestorVariationsTest,
    ::testing::Values(
        // Test cases where expected values are 2^n mod 1000000007
        AncestorVariationsTestCase{0, 1},           // 2^0 = 1
        AncestorVariationsTestCase{1, 2},           // 2^1 = 2
        AncestorVariationsTestCase{2, 4},           // 2^2 = 4
        AncestorVariationsTestCase{3, 8},           // 2^3 = 8
        AncestorVariationsTestCase{4, 16},          // 2^4 = 16
        AncestorVariationsTestCase{5, 32},          // 2^5 = 32
        AncestorVariationsTestCase{10, 1024},       // 2^10 = 1024
        AncestorVariationsTestCase{20, 1048576},    // 2^20 = 1048576
        AncestorVariationsTestCase{30, 73741817},   // 2^30 mod 1000000007
        AncestorVariationsTestCase{60, 536396504}   // 2^60 mod 1000000007
    )
);
