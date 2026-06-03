#include <gtest/gtest.h>

#include "smoothNumbers.h"

struct SmoothNumbersTestCase {
    unsigned long input;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const SmoothNumbersTestCase& tc) {
        return os
            << "{ input: " << tc.input
            << ", expected: \"" << tc.expected << "\" }";
    }
};

class SmoothNumbersTest :
    public ::testing::TestWithParam<SmoothNumbersTestCase> {};

TEST_P(SmoothNumbersTest, ReturnsExpectedClassification) {
    EXPECT_EQ(
        smoothNumbers(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    SmoothNumbersTests,
    SmoothNumbersTest,
    ::testing::Values(
        // Existing tests
        SmoothNumbersTestCase{16,  "power of 2"},
        SmoothNumbersTestCase{36,  "3-smooth"},
        SmoothNumbersTestCase{60,  "Hamming number"},
        SmoothNumbersTestCase{98,  "humble number"},
        SmoothNumbersTestCase{111, "non-smooth"},

        // Powers of 2
        SmoothNumbersTestCase{2,   "power of 2"},
        SmoothNumbersTestCase{4,   "power of 2"},
        SmoothNumbersTestCase{1024,"power of 2"},

        // 3-smooth
        SmoothNumbersTestCase{3,   "3-smooth"},
        SmoothNumbersTestCase{9,   "3-smooth"},
        SmoothNumbersTestCase{54,  "3-smooth"},

        // Hamming numbers (largest prime factor 5)
        SmoothNumbersTestCase{5,   "Hamming number"},
        SmoothNumbersTestCase{10,  "Hamming number"},
        SmoothNumbersTestCase{75,  "Hamming number"},

        // Humble numbers (largest prime factor 7)
        SmoothNumbersTestCase{7,   "humble number"},
        SmoothNumbersTestCase{14,  "humble number"},
        SmoothNumbersTestCase{210, "humble number"},

        // Non-smooth
        SmoothNumbersTestCase{11,  "non-smooth"},
        SmoothNumbersTestCase{13,  "non-smooth"},
        SmoothNumbersTestCase{121, "non-smooth"},
        SmoothNumbersTestCase{143, "non-smooth"}
    )
);

TEST(SmoothNumbersEdgeTest, OneIsOutOfRange) {
    EXPECT_EQ(
        smoothNumbers(1),
        "power of 2"
    );
}

TEST(SmoothNumbersEdgeTest, ZeroIsClassifiedAsPowerOfTwo) {
    EXPECT_EQ(
        smoothNumbers(0),
        "power of 2"
    );
}
