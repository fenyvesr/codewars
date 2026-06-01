#include <gtest/gtest.h>

#include "redacted.h"

TEST(RedactedTest, BasicCases) {
    EXPECT_TRUE(
        redacted(
            "TOP SECRET:\n"
            "The missile launch code for Sunday XXXXXXXXXX is:\n"
            "XXXXXXXXXXXXXXXXX",
            "TOP SECRET:\n"
            "The missile launch code for Sunday 5th August is:\n"
            "7-ZERO-8X-ALPHA-1"
        )
    );

    EXPECT_FALSE(
        redacted(
            "The name of the mole is Professor XXXXX",
            "The name of the mole is Professor Dinglemouse"
        )
    );

    EXPECT_TRUE(
        redacted(
            "XXXXXXXX XXXXXXX XXXXXXXXXXXXXXXXXXX\n"
            "XXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXX XXXXXXXXXXXXX XXXXX",
            "Area-51. Medical Report. 23/Oct/1969\n"
            "E.T. subject 4 was given an aspirin after reporting sick for duty today"
        )
    );
}
