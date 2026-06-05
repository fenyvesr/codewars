#include <gtest/gtest.h>

#include "offloadYourWork.h"

#include <ostream>
#include <string>
#include <utility>
#include <vector>

struct OffloadYourWorkTestCase {
    int projectMinutes;
    std::vector<std::pair<int, int>> freelancers;
    std::string expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const OffloadYourWorkTestCase& tc) {
        os << "{ projectMinutes: " << tc.projectMinutes
           << ", freelancers: {";
        for (const auto& freelancer : tc.freelancers) {
            os << "(" << freelancer.first << ", " << freelancer.second << "), ";
        }
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

INSTANTIATE_TEST_SUITE_P(
    OffloadYourWorkTests,
    OffloadYourWorkTest,
    ::testing::Values(
        // Original/basic examples
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

        // Empty freelancer list: verifies formatting of hours/minutes.
        OffloadYourWorkTestCase{
            1,
            {},
            "I need to work 0 hour(s) and 1 minute(s)"
        },
        OffloadYourWorkTestCase{
            59,
            {},
            "I need to work 0 hour(s) and 59 minute(s)"
        },
        OffloadYourWorkTestCase{
            60,
            {},
            "I need to work 1 hour(s) and 0 minute(s)"
        },
        OffloadYourWorkTestCase{
            61,
            {},
            "I need to work 1 hour(s) and 1 minute(s)"
        },
        OffloadYourWorkTestCase{
            119,
            {},
            "I need to work 1 hour(s) and 59 minute(s)"
        },
        OffloadYourWorkTestCase{
            120,
            {},
            "I need to work 2 hour(s) and 0 minute(s)"
        },

        // Exact completion and over-completion hit the Easy Money branch.
        OffloadYourWorkTestCase{
            0,
            {},
            "Easy Money!"
        },
        OffloadYourWorkTestCase{
            0,
            {{5, 0}},
            "Easy Money!"
        },
        OffloadYourWorkTestCase{
            120,
            {{2, 0}},
            "Easy Money!"
        },
        OffloadYourWorkTestCase{
            120,
            {{1, 30}, {0, 30}},
            "Easy Money!"
        },
        OffloadYourWorkTestCase{
            60,
            {{2, 0}},
            "Easy Money!"
        },

        // Multiple freelancers with mixed hour/minute contributions.
        OffloadYourWorkTestCase{
            300,
            {{1, 0}, {1, 30}, {0, 45}},
            "I need to work 1 hour(s) and 45 minute(s)"
        },
        OffloadYourWorkTestCase{
            500,
            {{2, 15}, {1, 45}, {0, 20}},
            "I need to work 4 hour(s) and 0 minute(s)"
        },
        OffloadYourWorkTestCase{
            500,
            {{0, 125}, {2, 35}},
            "I need to work 3 hour(s) and 40 minute(s)"
        },

        // Freelancer minutes are not normalized by the implementation, but are still counted.
        OffloadYourWorkTestCase{
            180,
            {{0, 90}},
            "I need to work 1 hour(s) and 30 minute(s)"
        },
        OffloadYourWorkTestCase{
            180,
            {{1, 75}},
            "I need to work 0 hour(s) and 45 minute(s)"
        },
        OffloadYourWorkTestCase{
            180,
            {{0, 180}},
            "Easy Money!"
        },

        // Deterministic behavior for negative inputs/contributions.
        OffloadYourWorkTestCase{
            -1,
            {},
            "Easy Money!"
        },
        OffloadYourWorkTestCase{
            60,
            {{0, -1}},
            "I need to work 1 hour(s) and 1 minute(s)"
        },
        OffloadYourWorkTestCase{
            60,
            {{-1, 0}},
            "I need to work 2 hour(s) and 0 minute(s)"
        },
        OffloadYourWorkTestCase{
            60,
            {{-1, 30}},
            "I need to work 1 hour(s) and 30 minute(s)"
        }
    )
);
