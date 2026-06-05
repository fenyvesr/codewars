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
        for (auto val : tc.expected)
            os << val << ", ";
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

INSTANTIATE_TEST_SUITE_P(
    LeonardoNumbersTests,
    LeonardoNumbersTest,
    ::testing::Values(
        // Existing / kata-like examples
        LeonardoNumbersTestCase{5, 1, 1, 1, {1, 1, 3, 5, 9}},
        LeonardoNumbersTestCase{5, 0, 0, 2, {0, 0, 2, 4, 8}},
        LeonardoNumbersTestCase{5, 0, 0, 0, {0, 0, 0, 0, 0}},

        // Boundary cases for the while condition: while (2 < n--)
        LeonardoNumbersTestCase{3, 1, 1, 1, {1, 1, 3}},      // loop enters exactly once
        LeonardoNumbersTestCase{2, 1, 1, 1, {1, 1}},         // loop skipped
        LeonardoNumbersTestCase{1, 5, 7, 3, {5, 7}},         // implementation still returns the two seeds
        LeonardoNumbersTestCase{0, 5, 7, 3, {5, 7}},         // non-positive n: loop skipped
        LeonardoNumbersTestCase{-1, 5, 7, 3, {5, 7}},        // negative n: loop skipped

        // Different seeds and Fibonacci-like behavior
        LeonardoNumbersTestCase{5, 2, 3, 1, {2, 3, 6, 10, 17}},
        LeonardoNumbersTestCase{6, 1, 2, 0, {1, 2, 3, 5, 8, 13}},
        LeonardoNumbersTestCase{7, 2, 1, 0, {2, 1, 3, 4, 7, 11, 18}},

        // Negative add values
        LeonardoNumbersTestCase{5, 1, 1, -1, {1, 1, 1, 1, 1}},
        LeonardoNumbersTestCase{6, 3, 4, -2, {3, 4, 5, 7, 10, 15}},

        // Negative and mixed starting values
        LeonardoNumbersTestCase{5, -1, 1, 0, {-1, 1, 0, 1, 1}},
        LeonardoNumbersTestCase{6, -5, -3, 1, {-5, -3, -7, -9, -15, -23}},
        LeonardoNumbersTestCase{6, -2, 5, 2, {-2, 5, 5, 12, 19, 33}},

        // Larger sequence, still safely inside int range
        LeonardoNumbersTestCase{8, 1, 1, 1, {1, 1, 3, 5, 9, 15, 25, 41}},
        LeonardoNumbersTestCase{10, 0, 1, 1, {0, 1, 2, 4, 7, 12, 20, 33, 54, 88}},

        // Zeros mixed with non-zero add/seed values
        LeonardoNumbersTestCase{4, 0, 5, 0, {0, 5, 5, 10}},
        LeonardoNumbersTestCase{4, 5, 0, 0, {5, 0, 5, 5}},
        LeonardoNumbersTestCase{4, 0, 0, -1, {0, 0, -1, -2}}
    )
);
