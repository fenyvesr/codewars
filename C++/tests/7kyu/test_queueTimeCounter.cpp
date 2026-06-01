#include <gtest/gtest.h>

#include "queueTimeCounter.h"

TEST(QueueTimeCounterTest, BasicCases) {
    EXPECT_EQ(queueTimeCounter({2, 5, 3, 6, 4}, 0), 6);
    EXPECT_EQ(queueTimeCounter({2, 5, 3, 6, 4}, 1), 18);
    EXPECT_EQ(queueTimeCounter({2, 5, 3, 6, 4}, 2), 12);
    EXPECT_EQ(queueTimeCounter({2, 5, 3, 6, 4}, 3), 20);
    EXPECT_EQ(queueTimeCounter({2, 5, 3, 6, 4}, 4), 17);
}
