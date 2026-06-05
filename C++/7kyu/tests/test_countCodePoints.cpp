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

INSTANTIATE_TEST_SUITE_P(
    CountCodepointsTests,
    CountCodepointsTest,
    ::testing::Values(
    // Original/basic examples
    CountCodepointsTestCase{u8"", 0},
    CountCodepointsTestCase{"A\xC3\xBF\xE2\x99\xA0\xF0\x9F\x99\x89", 4},
    CountCodepointsTestCase{"\xC3\xA9", 1},
    CountCodepointsTestCase{"e\xCC\x81", 2},
    CountCodepointsTestCase{"\xE3\x90\xB7\xC2\xA9\xE2\x88\x8F!\xE9\x87\x8D", 5}
    )
);
