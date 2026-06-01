#include <gtest/gtest.h>

#include "stringPacketBasedCommunication.h"

TEST(StringPacketBasedCommunicationTest, BasicCases) {
    EXPECT_EQ(
        stringPacketBasedCommunication("H1H10F1200120008F4F4"),
        "H1H1FFFF00200000F4F4"
    );

    EXPECT_EQ(
        stringPacketBasedCommunication("X7X7B7A201400058L0L0"),
        "X7X7FFFF00820000L0L0"
    );

    EXPECT_EQ(
        stringPacketBasedCommunication("R5R5C3D900120008K4K4"),
        "R5R5FFFF00960000K4K4"
    );
}
