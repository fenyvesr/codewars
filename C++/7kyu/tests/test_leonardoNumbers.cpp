#include <gtest/gtest.h>

#include "leonardoNumbers.h"

struct LeonardoNumbersTestCase {
    int n;
    int L0;
    int L1;
    int add;
    std::vector<int> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const LeonardoNumbersTestCase& tc) {
        os << "{ n: " << tc.n
            << ", L0: " << tc.L0
            << ", L1: " << tc.L1
            << ", add: " << tc.add
            << ", expected: {";
        for(auto val : tc.expected) os << val << ", ";
        return os << "} }";
    }
};

class LeonardoNumbersTest :
    public ::testing::TestWithParam<LeonardoNumbersTestCase> {};

TEST_P(LeonardoNumbersTest, ReturnsExpectedSequence) {
    EXPECT_EQ(
        leonardoNumbers(
            GetParam().n,
            GetParam().L0,
            GetParam().L1,
            GetParam().add
        ),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    LeonardoNumbersTests,
    LeonardoNumbersTest,
    ::testing::Values(
        // Existing tests
        LeonardoNumbersTestCase{5, 1, 1, 1, {1, 1, 3, 5, 9}},
        LeonardoNumbersTestCase{5, 0, 0, 2, {0, 0, 2, 4, 8}},
        LeonardoNumbersTestCase{5, 0, 0, 0, {0, 0, 0, 0, 0}},

        // Exactly two elements
        LeonardoNumbersTestCase{2, 1, 1, 1, {1, 1}},

        // Smallest sensible n
        LeonardoNumbersTestCase{1, 5, 7, 3, {5, 7}},

        // Different seeds
        LeonardoNumbersTestCase{5, 2, 3, 1, {2, 3, 6, 10, 17}},
        LeonardoNumbersTestCase{6, 1, 2, 0, {1, 2, 3, 5, 8, 13}},

        // Negative add
        LeonardoNumbersTestCase{5, 1, 1, -1, {1, 1, 1, 1, 1}},

        // Negative starting values
        LeonardoNumbersTestCase{5, -1, 1, 0, {-1, 1, 0, 1, 1}},

        // Larger sequence
        LeonardoNumbersTestCase{8, 1, 1, 1, {1, 1, 3, 5, 9, 15, 25, 41}}
    )
);
