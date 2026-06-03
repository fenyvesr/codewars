#include <gtest/gtest.h>

#include "queueTimeCounter.h"

struct QueueTimeCounterTestCase {
    std::vector<int> queuers;
    int pos;
    long long expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const QueueTimeCounterTestCase& tc) {
        os << "{ queuers: {";
        for(const auto& queuer : tc.queuers)
            os << queuer << ", ";
        return os << "}, pos: " << tc.pos << ", expected: " << tc.expected << " }";
    }
};

class QueueTimeCounterTest :
    public ::testing::TestWithParam<QueueTimeCounterTestCase> {};

TEST_P(QueueTimeCounterTest, ReturnsExpectedTime) {
    EXPECT_EQ(
        queueTimeCounter(
            GetParam().queuers,
            GetParam().pos
        ),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    QueueTimeCounterTests,
    QueueTimeCounterTest,
    ::testing::Values(
        // Existing tests
        QueueTimeCounterTestCase{{2, 5, 3, 6, 4}, 0, 6},
        QueueTimeCounterTestCase{{2, 5, 3, 6, 4}, 1, 18},
        QueueTimeCounterTestCase{{2, 5, 3, 6, 4}, 2, 12},
        QueueTimeCounterTestCase{{2, 5, 3, 6, 4}, 3, 20},
        QueueTimeCounterTestCase{{2, 5, 3, 6, 4}, 4, 17},

        // Single person
        QueueTimeCounterTestCase{{1}, 0, 1},
        QueueTimeCounterTestCase{{5}, 0, 5},

        // Two people
        QueueTimeCounterTestCase{{1, 1}, 0, 1},
        QueueTimeCounterTestCase{{1, 1}, 1, 2},

        // All same
        QueueTimeCounterTestCase{{3, 3, 3}, 0, 7},
        QueueTimeCounterTestCase{{3, 3, 3}, 1, 8},
        QueueTimeCounterTestCase{{3, 3, 3}, 2, 9},

        // Person wants only one ticket
        QueueTimeCounterTestCase{{5, 1, 5}, 1, 2},

        // Last position
        QueueTimeCounterTestCase{{1, 2, 3, 4}, 3, 10},

        // First position
        QueueTimeCounterTestCase{{10, 10, 10}, 0, 28},

        // Mixed zeros
        QueueTimeCounterTestCase{{0}, 0, 0},
        QueueTimeCounterTestCase{{0, 5}, 0, -1},
        QueueTimeCounterTestCase{{5, 0}, 1, 0}
    )
);
