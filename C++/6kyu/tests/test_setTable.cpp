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

INSTANTIATE_TEST_SUITE_P(
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
            {"Artlu"},
            {"_____", "_____", "_____", "_____", "_____", "_____", "Artlu", "_____", "_____", "_____", "_____", "_____"}
        },
        SetTableTestCase{
            {"Artlu", "Breca", "Cityl", "Dedaf"},
            {"Cityl", "_____", "_____", "_____", "_____", "Breca", "Artlu", "_____", "_____", "_____", "_____", "Dedaf"}
        },
        // Test with full list of 12 ghosts
        SetTableTestCase{
            {"Sevap", "Syolc", "Sgulg", "Stolb", "Sknoh", "Spord", "Sgnaf", "Shcat", "Sknit", "Snirg", "Senin", "Sliob"},
            {"Sgnaf", "Sknit", "Senin", "Sliob", "Snirg", "Shcat", "Spord", "Stolb", "Syolc", "Sevap", "Sgulg", "Sknoh"}
        },
        SetTableTestCase{
            {"Yojne", "Xenna", "Verap", "Ebyam", "Teseb", "Ycuag", "Onets", "Skcaw", "Yrovi", "Tpets", "Lizuf", "Girnu"},
            {"Teseb", "Onets", "Verap", "Xenna", "Ebyam", "Ycuag", "Yojne", "Yrovi", "Lizuf", "Skcaw", "Girnu", "Tpets"}
        },
        // Test with more than 12 ghosts (only first 12 are seated)
        SetTableTestCase{
            {"Egdob", "Liame", "Skceg", "Yesba", "Cinid", "Sallo", "Sumac", "Triks", "Sipat", "Elona", "Sreod", "Deyab", "Dlaps", "Nevey", "Htron"},
            {"Cinid", "Sreod", "Elona", "Egdob", "Deyab", "Yesba", "Liame", "Sipat", "Sallo", "Skceg", "Sumac", "Triks"}
        }
    )
);
