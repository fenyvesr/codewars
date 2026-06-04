#include <gtest/gtest.h>

#include "restoreBrackets.h"

struct RestoreBracketsTestCase {
    std::string input;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const RestoreBracketsTestCase& tc) {
        return os << "RestoreBracketsCase";;
    }
};

class RestoreBracketsTest :
    public ::testing::TestWithParam<RestoreBracketsTestCase> {};

TEST_P(RestoreBracketsTest, ReturnsExpectedString) {
    EXPECT_EQ(
        restore_brackets(GetParam().input),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    RestoreBracketsTests,
    RestoreBracketsTest,
    ::testing::Values(
        RestoreBracketsTestCase{"x", "x"},
        RestoreBracketsTestCase{"[xy", "[xy]"},
        RestoreBracketsTestCase{"[x[yy", "[x[yy]]"},
        RestoreBracketsTestCase{"[[xyy", "[[xy]y]"},
        RestoreBracketsTestCase{"[[ab[ab", "[[ab][ab]]"},
        RestoreBracketsTestCase{"[c[o[d[e[w[a[rs", "[c[o[d[e[w[a[rs]]]]]]]"},
        RestoreBracketsTestCase{"[[[Co[de[[wa[rs", "[[[Co][de]][[wa][rs]]]"},
        RestoreBracketsTestCase{"[[[[[[[codewars", "[[[[[[[co]d]e]w]a]r]s]"},
        RestoreBracketsTestCase{"[[[ab[cd[[ef[gh", "[[[ab][cd]][[ef][gh]]]"},
        RestoreBracketsTestCase{"[[[[ab[cd[[ef[gh[[[ij[kl[[mn[op", "[[[[ab][cd]][[ef][gh]]][[[ij][kl]][[mn][op]]]]"}
    ),
    [](const ::testing::TestParamInfo<RestoreBracketsTestCase>& info) {
        return "Case" + std::to_string(info.index);
    }
);
