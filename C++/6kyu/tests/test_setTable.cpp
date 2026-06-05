#include <gtest/gtest.h>

#include "setTable.h"

struct SetTableTestCase {
    std::vector<std::string> input;
    std::vector<std::string> expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const SetTableTestCase& tc) {
        os  << "{ input: [";
        for (const auto& name : tc.input)
            os << name << ", ";
        os << "], expected: [";
        for (const auto& name : tc.expected)
            os << name << ", ";
        os << "] }";
        return os;
    }
};

class SetTableTest :
    public ::testing::TestWithParam<SetTableTestCase> {};

TEST_P(SetTableTest, ReturnsExpectedSeating) {
    EXPECT_EQ(
        set_table(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    SetTableTests,
    SetTableTest,
    ::testing::Values(
        // Test with empty list
        SetTableTestCase{
            {},
            {"_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____", "_____"}
        },
        // Test with single ghost
        SetTableTestCase{
            {"Yojne"},
            {"_____", "_____", "_____", "_____", "_____", "_____", "Yojne", "_____", "_____", "_____", "_____", "_____"}
        },
        // Test with full list of 12 ghosts
        SetTableTestCase{
            {"Yojne", "Xenna", "Verap", "Ebyam", "Teseb", "Ycuag", "Onets", "Skcaw", "Yrovi", "Tpets", "Lizuf", "Girnu"},
            {"Teseb", "Onets", "Verap", "Xenna", "Ebyam", "Ycuag", "Yojne", "Yrovi", "Lizuf", "Skcaw", "Girnu", "Tpets"}
        },
        // Test with more than 12 ghosts (only first 12 are seated)
        SetTableTestCase{
            {"Yojne", "Xenna", "Verap", "Ebyam", "Teseb", "Ycuag", "Onets", "Skcaw", "Yrovi", "Tpets", "Lizuf", "Girnu", "Extra", "More"},
            {"Teseb", "Onets", "Verap", "Xenna", "Ebyam", "Ycuag", "Yojne", "Yrovi", "Lizuf", "Skcaw", "Girnu", "Tpets"}
        }
    )
);
