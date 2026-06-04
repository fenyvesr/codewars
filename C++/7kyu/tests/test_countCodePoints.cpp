#include <gtest/gtest.h>

#include "countCodePoints.h"

struct CountCodepointsTestCase {
    std::string input;
    std::size_t expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const CountCodepointsTestCase& tc) {
        os << "{ input: \"" << tc.input
           << "\", expected: " << tc.expected << " }";
        return os;
    }
};

class CountCodepointsTest :
    public ::testing::TestWithParam<CountCodepointsTestCase> {};

TEST_P(CountCodepointsTest, CountsCorrectly) {
    EXPECT_EQ(CountCodepoints(GetParam().input), GetParam().expected);
}

INSTANTIATE_TEST_CASE_P(
    CountCodepointsTests,
    CountCodepointsTest,
    ::testing::Values(
        // Original/basic examples
        CountCodepointsTestCase{u8"", 0},
        CountCodepointsTestCase{u8"Aÿ♠🙉", 4},
        CountCodepointsTestCase{u8"é", 1}, // (actual é character)
        CountCodepointsTestCase{u8"é", 2}, // (e + combining acute accent)
        CountCodepointsTestCase{u8"㐷©∏!重", 5}
    )
);
