#include <gtest/gtest.h>

#include "subArrayElementsSum.h"

struct SubArrayElementsTestCase {
    std::vector<std::vector<int>> input;
    int d;
    long expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const SubArrayElementsTestCase& tc) {
        os << "{ input: {";
        for (const auto& subarray : tc.input) {
            os << "{";
            for (const auto& element : subarray)
                os << element << ", ";
            os << "}, ";
        }
        return os << "}, d: " << tc.d << ", expected: " << tc.expected << " }";
    }
};

class SubArrayElementsSumTest :
    public ::testing::TestWithParam<SubArrayElementsTestCase> {};

TEST_P(SubArrayElementsSumTest, ReturnsExpectedSum) {
    EXPECT_EQ(
        subArrayElementsSum(GetParam().input, GetParam().d),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    SubArrayElementsSumTests,
    SubArrayElementsSumTest,
    ::testing::Values(
        // Existing tests
        SubArrayElementsTestCase{
            {{3,2,1,0}, {4,6,5,3,2}, {9,8,7,4}},
            0,
            16
        },
        SubArrayElementsTestCase{
            {{3}, {4,6,5,3,2}, {9,8,7,4}},
            0,
            15
        },
        SubArrayElementsTestCase{
            {{3,2,1,0}, {4,6,5,3,2}, {}},
            0,
            7
        },
        SubArrayElementsTestCase{
            {{3,2,1,0}, {4,6,5,3,2}, {}},
            5,
            12
        },
        SubArrayElementsTestCase{
            {{3,2}, {4}, {}},
            0,
            0
        },

        // Single subarray
        SubArrayElementsTestCase{
            {{5}},
            0,
            5
        },

        // Single subarray, fallback
        SubArrayElementsTestCase{
            {{}},
            7,
            7
        },

        // All fallbacks
        SubArrayElementsTestCase{
            {{}, {}, {}},
            2,
            6
        },

        // Exact boundary indices
        SubArrayElementsTestCase{
            {{1,2,3}, {4,5}, {6}},
            0,
            14   // 3 + 5 + 6
        },

        // Negative values
        SubArrayElementsTestCase{
            {{-1,-2,-3}, {-4,-5}, {-6}},
            0,
            -14
        },

        // Mixed fallback and valid
        SubArrayElementsTestCase{
            {{1}, {}, {3}},
            10,
            23   // 10 + 10 + 3
        }
    )
);

TEST(SubArrayElementsSumEdgeTest, EmptyOuterVectorReturnsZero) {
    EXPECT_EQ(
        subArrayElementsSum({}, 5),
        0
    );
}

TEST(SubArrayElementsSumEdgeTest, NegativeFallbackValue) {
    EXPECT_EQ(
        subArrayElementsSum({{}, {}}, -3),
        -6
    );
}
