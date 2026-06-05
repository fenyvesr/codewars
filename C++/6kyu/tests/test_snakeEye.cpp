#include <gtest/gtest.h>

#include "snakeEye.h"

struct SnakeEyeTestCase {
    SnakeEye o;
    std::size_t expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const SnakeEyeTestCase& tc) {
        return os
            << "{ n: " << tc.o.size()
            << ", expected: " << tc.expected << " }";
    }
};

class SnakeEyeTest :
    public ::testing::TestWithParam<SnakeEyeTestCase> {};

TEST_P(SnakeEyeTest, ReturnsExpectedSize) {
    EXPECT_EQ(
        GetParam().o.size(),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    SnakeEyeTests,
    SnakeEyeTest,
    ::testing::Values(
        // Existing tests
        SnakeEyeTestCase{(SnakeEye() > SnakeEye()) - 0 - 0 - 0 - 0, 13},
        SnakeEyeTestCase{(SnakeEye() > SnakeEye()) - 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0, 21}
    )
);