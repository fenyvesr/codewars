#include <gtest/gtest.h>

#include "midiFiles.h"

struct MidiFilesTestCase {
    int n;
    std::vector<int> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const MidiFilesTestCase& tc) {
        os  << "{ n: " << tc.n
            << ", expected: {";
        for(const auto& byte : tc.expected)
            os << byte << ", ";
        return os << "} }";
    }
};

class MidiFilesTest :
    public ::testing::TestWithParam<MidiFilesTestCase> {};

TEST_P(MidiFilesTest, ReturnsExpectedEncoding) {
    EXPECT_EQ(
        encode(GetParam().n),
        GetParam().expected
    );

    EXPECT_EQ(
        decode(encode(GetParam().n)),
        GetParam().n
    );
}

INSTANTIATE_TEST_SUITE_P(
    MidiFilesTests,
    MidiFilesTest,
    ::testing::Values(
        // Existing tests
        MidiFilesTestCase{128, {0x81, 0x00}},
        MidiFilesTestCase{2097151, {0xFF, 0xFF, 0x7F}},
        MidiFilesTestCase{0, {0x00}},
        MidiFilesTestCase{127, {0x7F}},
        MidiFilesTestCase{55, {0x37}},
        MidiFilesTestCase{69, {0x45}},
        MidiFilesTestCase{16383, {0xFF, 0x7F}},
        MidiFilesTestCase{8192, {0xC0, 0x00}},
        MidiFilesTestCase{6969, {0xB6, 0x39}},
        MidiFilesTestCase{2097152, {0x81, 0x80, 0x80, 0x00}},
        MidiFilesTestCase{268435455, {0xFF, 0xFF, 0xFF, 0x7F}},
        MidiFilesTestCase{134217728, {0xC0, 0x80, 0x80, 0x00}},
        MidiFilesTestCase{69696969, {0xA1, 0x9D, 0xFB, 0x49}}
    )
);

struct MidiFilesDecodeTestCase {
    std::vector<int> data;
    int expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const MidiFilesDecodeTestCase& tc) {
        os  << "{ data: {";
        for(const auto& byte : tc.data)
            os << byte << ", ";
        return os << "}, expected: " << tc.expected << " }";
    }
};

class MidiFilesDecodeTest :
    public ::testing::TestWithParam<MidiFilesDecodeTestCase> {};

TEST_P(MidiFilesDecodeTest, ReturnsExpectedDecoding) {
    EXPECT_EQ(
        decode(GetParam().data),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    MidiFilesDecodeTests,
    MidiFilesDecodeTest,
    ::testing::Values(
        // Existing tests
        MidiFilesDecodeTestCase{{0x81, 0x00}, 128},
        MidiFilesDecodeTestCase{{0xFF, 0xFF, 0x7F}, 2097151},
        MidiFilesDecodeTestCase{{0x00}, 0},
        MidiFilesDecodeTestCase{{0x7F}, 127},
        MidiFilesDecodeTestCase{{0x37}, 55},
        MidiFilesDecodeTestCase{{0x45}, 69},
        MidiFilesDecodeTestCase{{0x00, 0x7F, 0x7F}, 0},
        MidiFilesDecodeTestCase{{0x7F, 0x81, 0x00}, 127},
        MidiFilesDecodeTestCase{{0x45, 0x45, 0x45}, 69},
        MidiFilesDecodeTestCase{{0x37, 0xFF, 0xFF, 0x7F}, 55},
        MidiFilesDecodeTestCase{{0x81, 0x00}, 128},
        MidiFilesDecodeTestCase{{0xFF, 0x7F}, 16383},
        MidiFilesDecodeTestCase{{0xC0, 0x00}, 8192},
        MidiFilesDecodeTestCase{{0xB6, 0x39}, 6969},
        MidiFilesDecodeTestCase{{0x81, 0x00, 0xFF}, 128},
        MidiFilesDecodeTestCase{{0xFF, 0x7F, 0x00}, 16383},
        MidiFilesDecodeTestCase{{0xC0, 0x00, 0x81, 0x80, 0x00}, 8192},
        MidiFilesDecodeTestCase{{0xB6, 0x39, 0xFF, 0xFF}, 6969},
        MidiFilesDecodeTestCase{{0x81, 0x80, 0x80, 0x00}, 2097152},
        MidiFilesDecodeTestCase{{0xFF, 0xFF, 0xFF, 0x7F}, 268435455},
        MidiFilesDecodeTestCase{{0xC0, 0x80, 0x80, 0x00}, 134217728},
        MidiFilesDecodeTestCase{{0xA1, 0x9D, 0xFB, 0x49}, 69696969},
        MidiFilesDecodeTestCase{{0x81, 0x80, 0x80, 0x00, 0x7F}, 2097152},
        MidiFilesDecodeTestCase{{0xFF, 0xFF, 0xFF, 0x7F, 0x81, 0x00}, 268435455},
        MidiFilesDecodeTestCase{{0xC0, 0x80, 0x80, 0x00, 0xFF, 0xFF, 0x7F}, 134217728},
        MidiFilesDecodeTestCase{{0xA1, 0x9D, 0xFB, 0x49, 0x00, 0x00}, 69696969}
    )
);
