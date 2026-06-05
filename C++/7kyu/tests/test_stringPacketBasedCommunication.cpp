#include <gtest/gtest.h>

#include "stringPacketBasedCommunication.h"

struct StringPacketBasedCommunicationTestCase {
    std::string input;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const StringPacketBasedCommunicationTestCase& tc) {
        return os
            << "{ input: \"" << tc.input
            << "\", expected: \"" << tc.expected
            << "\" }";
    }
};

class StringPacketBasedCommunicationTest :
    public ::testing::TestWithParam<StringPacketBasedCommunicationTestCase> {};

TEST_P(StringPacketBasedCommunicationTest, ConvertsPacketCorrectly) {
    EXPECT_EQ(
        stringPacketBasedCommunication(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    ValidPackets,
    StringPacketBasedCommunicationTest,
    ::testing::Values(
        // Existing basic cases
        StringPacketBasedCommunicationTestCase{"H1H10F1200120008F4F4", "H1H1FFFF00200000F4F4"},
        StringPacketBasedCommunicationTestCase{"X7X7B7A201400058L0L0", "X7X7FFFF00820000L0L0"},
        StringPacketBasedCommunicationTestCase{"R5R5C3D900120008K4K4", "R5R5FFFF00960000K4K4"},

        // Padding edge cases
        StringPacketBasedCommunicationTestCase{"AB120F1200010002CD34", "AB12FFFF00030000CD34"},
        StringPacketBasedCommunicationTestCase{"AB120F1200100002CD34", "AB12FFFF00120000CD34"},
        StringPacketBasedCommunicationTestCase{"AB120F1201000002CD34", "AB12FFFF01020000CD34"},
        StringPacketBasedCommunicationTestCase{"AB120F1210000002CD34", "AB12FFFF10020000CD34"},
        StringPacketBasedCommunicationTestCase{"AB12C3D900110011CD34", "AB12FFFF01210000CD34"},

        // Clamp edge cases
        StringPacketBasedCommunicationTestCase{"AB12B7A200010002CD34", "AB12FFFF00000000CD34"},
        StringPacketBasedCommunicationTestCase{"AB12B7A200020002CD34", "AB12FFFF00000000CD34"},
        StringPacketBasedCommunicationTestCase{"AB12C3D901000100CD34", "AB12FFFF99990000CD34"},
        StringPacketBasedCommunicationTestCase{"AB120F1249995000CD34", "AB12FFFF99990000CD34"},

        // Boundary values
        StringPacketBasedCommunicationTestCase{"00000F12000000009999", "0000FFFF000000009999"},
        StringPacketBasedCommunicationTestCase{"00000F12999900009999", "0000FFFF999900009999"},
        StringPacketBasedCommunicationTestCase{"0000B7A2999900009999", "0000FFFF999900009999"},
        StringPacketBasedCommunicationTestCase{"0000C3D9000009999999", "0000FFFF000000009999"},
        StringPacketBasedCommunicationTestCase{"AB12C3D901010099CD34", "AB12FFFF99990000CD34"},
        StringPacketBasedCommunicationTestCase{"AB12B7A200100001CD34", "AB12FFFF00090000CD34"}
    )
);

TEST(StringPacketBasedCommunicationCrashTest, ThrowsForUnknownInstructionCode) {
    EXPECT_THROW(
        stringPacketBasedCommunication("AB12DEAD00010002CD34"),
        std::invalid_argument
    );
}

TEST(StringPacketBasedCommunicationCrashTest, ThrowsForTooShortPacket) {
    EXPECT_THROW(
        stringPacketBasedCommunication("AB120F1200010002"),
        std::invalid_argument
    );
}

TEST(StringPacketBasedCommunicationCrashTest, ThrowsForTooLongPacket) {
    EXPECT_THROW(
        stringPacketBasedCommunication("AB120F1200010002CD34XX"),
        std::invalid_argument
    );
}

TEST(StringPacketBasedCommunicationCrashTest, ThrowsForNonDigitOperand) {
    EXPECT_THROW(
        stringPacketBasedCommunication("AB120F12AA010002CD34"),
        std::invalid_argument
    );
}

TEST(StringPacketBasedCommunicationCrashTest, ThrowsForMissingPacket) {
    EXPECT_THROW(
        stringPacketBasedCommunication(""),
        std::invalid_argument
    );
}
