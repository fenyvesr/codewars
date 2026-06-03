#include <gtest/gtest.h>

#include "cigarStringsEasy.h"

struct CigarStringsEasyTestCase {
    std::string cigar;
    std::string sequence;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const CigarStringsEasyTestCase& tc) {
        return os
            << "{ cigar: \"" << tc.cigar
            << "\", sequence: \"" << tc.sequence
            << "\", expected: \"" << tc.expected
            << "\" }";
    }
};

class CigarStringsEasyTest :
    public ::testing::TestWithParam<CigarStringsEasyTestCase> {};

TEST_P(CigarStringsEasyTest, ReturnsExpectedResult) {
    EXPECT_EQ(
        cigarStringsEasy(GetParam().cigar, GetParam().sequence),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    CigarStringsEasyTests,
    CigarStringsEasyTest,
    ::testing::Values(
        // Existing tests
        CigarStringsEasyTestCase{"5M", "ACTGC", "True"},
        CigarStringsEasyTestCase{"3M2S", "ACTGC", "False"},
        CigarStringsEasyTestCase{"4M2S", "ACTGC", "Invalid cigar"},

        // Additional valid cases
        CigarStringsEasyTestCase{"1M", "A", "True"},
        CigarStringsEasyTestCase{"10M", "ACTGACTGAC", "True"},
        CigarStringsEasyTestCase{"2M3S", "ACTGC", "False"},
        CigarStringsEasyTestCase{"1S4M", "ACTGC", "False"},
        CigarStringsEasyTestCase{"2M2I1D", "ACTGC", "False"},
        CigarStringsEasyTestCase{"0005M", "ACTGC", "False"},   // "5M" != "0005M"
        CigarStringsEasyTestCase{"0M", "", "True"},
        CigarStringsEasyTestCase{"0S", "", "False"},

        // Length mismatch
        CigarStringsEasyTestCase{"5M", "ACTG", "Invalid cigar"},
        CigarStringsEasyTestCase{"0M", "A", "Invalid cigar"},
        CigarStringsEasyTestCase{"1M1S", "A", "Invalid cigar"},

        // Multi-digit numbers
        CigarStringsEasyTestCase{"12M", std::string(12, 'A'), "True"},
        CigarStringsEasyTestCase{"10M2S", std::string(12, 'A'), "False"}
    )
);

TEST(CigarStringsEasyCrashTest, ThrowsOnIntegerOverflow) {
    EXPECT_THROW(
        cigarStringsEasy("999999999999999999999999999M", ""),
        std::out_of_range
    );
}
