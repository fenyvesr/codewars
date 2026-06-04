#include <gtest/gtest.h>

#include "jumbler.h"

struct JumblerTestCase {
    std::vector<std::size_t> indices;
    unsigned expected;


    friend std::ostream& operator<<(std::ostream& os,
                                    const JumblerTestCase& tc) {
        os << "{ indices: ";
        for (auto val : tc.indices)
            os << val << ", ";
        return os
            << "}"
            << ", expected: " << tc.expected
            << " }";
    }
};

class JumblerTest :
    public ::testing::TestWithParam<JumblerTestCase> {};

TEST_P(JumblerTest, ReturnsExpectedResult) {
    EXPECT_EQ(
        jumbler(GetParam().indices),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    JumblerTests,
    JumblerTest,
    ::testing::Values(
        // Existing tests
        JumblerTestCase{{0}, 0},
        JumblerTestCase{{1, 0}, 1},
        JumblerTestCase{{2, 0, 1}, 3},
        JumblerTestCase{{3, 0, 1, 2}, 2},
        JumblerTestCase{{3, 1, 4, 2, 0}, 6},
        JumblerTestCase{{5, 3, 1, 0, 4, 2}, 9},
        JumblerTestCase{{5, 2, 4, 0, 1, 6, 3}, 7},
        JumblerTestCase{{5, 3, 6, 7, 0, 4, 1, 2}, 9},
        JumblerTestCase{{2, 6, 8, 3, 5, 4, 0, 7, 1}, 12},
        JumblerTestCase{{8, 5, 9, 6, 7, 1, 0, 2, 4, 3}, 6}
    )
);
