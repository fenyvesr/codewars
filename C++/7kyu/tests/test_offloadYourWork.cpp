#include <gtest/gtest.h>

#include "offloadYourWork.h"

struct OffloadYourWorkTestCase {
    int projectMinutes;
    std::vector<std::pair<int, int>> freelancers;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const OffloadYourWorkTestCase& tc) {
        os << "{ projectMinutes: " << tc.projectMinutes
            << ", freelancers: {";
        for(const auto& [hours, minutes] : tc.freelancers)
            os << "(" << hours << ", " << minutes << "), ";
        return os << "}, expected: \"" << tc.expected << "\" }";
    }
};

class OffloadYourWorkTest :
    public ::testing::TestWithParam<OffloadYourWorkTestCase> {};

TEST_P(OffloadYourWorkTest, ReturnsExpectedResult) {
    EXPECT_EQ(
        offloadYourWork(
            GetParam().projectMinutes,
            GetParam().freelancers
        ),
        GetParam().expected
    );
}

INSTANTIATE_TEST_CASE_P(
    OffloadYourWorkTests,
    OffloadYourWorkTest,
    ::testing::Values(
        // Existing tests
        OffloadYourWorkTestCase{
            60,
            {{1, 0}},
            "Easy Money!"
        },
        OffloadYourWorkTestCase{
            60,
            {{0, 0}},
            "I need to work 1 hour(s) and 0 minute(s)"
        },
        OffloadYourWorkTestCase{
            141,
            {{1, 55}, {0, 25}},
            "I need to work 0 hour(s) and 1 minute(s)"
        },

        // Exact completion
        OffloadYourWorkTestCase{
            120,
            {{2, 0}},
            "Easy Money!"
        },

        // More freelancer time than required
        OffloadYourWorkTestCase{
            60,
            {{2, 0}},
            "Easy Money!"
        },

        // No freelancers
        OffloadYourWorkTestCase{
            90,
            {},
            "I need to work 1 hour(s) and 30 minute(s)"
        },

        // Minutes only
        OffloadYourWorkTestCase{
            59,
            {},
            "I need to work 0 hour(s) and 59 minute(s)"
        },

        // Remaining exactly one minute
        OffloadYourWorkTestCase{
            61,
            {{1, 0}},
            "I need to work 0 hour(s) and 1 minute(s)"
        },

        // Multiple freelancers
        OffloadYourWorkTestCase{
            300,
            {{1, 0}, {1, 30}, {0, 45}},
            "I need to work 1 hour(s) and 45 minute(s)"
        },

        // Zero project
        OffloadYourWorkTestCase{
            0,
            {},
            "Easy Money!"
        },

        // Zero project, freelancers present
        OffloadYourWorkTestCase{
            0,
            {{5, 0}},
            "Easy Money!"
        },

        // Negative values produce odd but deterministic behavior.
        OffloadYourWorkTestCase{
            -1,
            {},
            "Easy Money!"
        },

        OffloadYourWorkTestCase{
            60,
            {{0, -1}},
            "I need to work 1 hour(s) and 1 minute(s)"
        }
    )
);

