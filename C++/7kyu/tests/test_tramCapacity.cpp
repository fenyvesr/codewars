#include <gtest/gtest.h>

#include "tramCapacity.h"

struct TramCapacityTestCase {
    int stops;
    std::vector<int> off;
    std::vector<int> on;
    int expected;

    friend std::ostream& operator<<(std::ostream& os,
                                    const TramCapacityTestCase& tc) {
        os << "{ stops: " << tc.stops
            << ", off: {";
        for(const auto& element : tc.off)
            os << element << ", ";
        os << "}, on: {";
        for(const auto& element : tc.on)
            os << element << ", ";
        return os << "}, expected: " << tc.expected << " }";
    }
};

class TramCapacityTest :
    public ::testing::TestWithParam<TramCapacityTestCase> {};

TEST_P(TramCapacityTest, ReturnsExpectedCapacity) {
    EXPECT_EQ(
        tramCapacity(
            GetParam().stops,
            GetParam().off,
            GetParam().on
        ),
        GetParam().expected
    );
}

INSTANTIATE_TEST_SUITE_P(
    TramCapacityTests,
    TramCapacityTest,
    ::testing::Values(
        // Existing tests
        TramCapacityTestCase{4,  {0,2,4,4},                   {3,5,2,0},                   6},
        TramCapacityTestCase{2,  {0,2,4,4},                   {3,5,2,0},                   6},
        TramCapacityTestCase{1,  {0,2,4,4},                   {3,5,2,0},                   3},
        TramCapacityTestCase{10, {0,1,2,3,4,5,6,7,8,9},       {9,8,7,6,5,4,3,2,1,0},      25},
        TramCapacityTestCase{5,  {0,2,4,14,2},                {3,5,14,0,0},               16},

        // Empty tram
        TramCapacityTestCase{0, {}, {}, 0},

        // Single stop
        TramCapacityTestCase{1, {0}, {5}, 5},
        TramCapacityTestCase{1, {3}, {0}, 0},

        // Exact fill and empty
        TramCapacityTestCase{2, {0,5}, {5,0}, 5},

        // Capacity reached at last stop
        TramCapacityTestCase{3, {0,0,0}, {1,2,3}, 6},

        // Capacity reached at first stop
        TramCapacityTestCase{3, {0,5,5}, {10,0,0}, 10},

        // No passengers ever enter
        TramCapacityTestCase{3, {0,0,0}, {0,0,0}, 0}
    )
);

TEST(TramCapacityCrashTest, ExceptionOnMismatchedVectorSizes) {
    EXPECT_THROW(
        {
            tramCapacity(3,
                         {0,2,4},
                         {3});
        },
        std::invalid_argument
    );
}

TEST(TramCapacityCrashTest, ExceptionOnNegativeStops) {
    EXPECT_THROW(
        {
            tramCapacity(-1,
                         {0,2,4},
                         {3});
        },
        std::invalid_argument
    );
}


TEST(TramCapacityCrashTest, ExceptionWithTooManyStops) {
    EXPECT_THROW(
        {
            tramCapacity(100,
                         {0,2,4},
                         {3,5,2});
        },
        std::invalid_argument
    );
}
