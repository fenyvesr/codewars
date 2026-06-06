#include <gtest/gtest.h>

#include "allocateRooms.h"

struct AllocateRoomsTestCase {
    std::vector<std::vector<int>> customers;
    // list of acceptable expected allocations; any match is considered correct
    std::vector<std::vector<int>> expected_options;

    friend std::ostream& operator<<(std::ostream& os,
                                    const AllocateRoomsTestCase& tc) {
        os << "{ customers: [";
        for (const auto& customer : tc.customers) {
            os << "[";
            for (auto v : customer) os << v << ",";
            os << "], ";
        }
        os << "], expected_options: [";
        for (const auto& opt : tc.expected_options) {
            os << "[";
            for (auto v : opt) os << v << ",";
            os << "], ";
        }
        os << "] }";
        return os;
    }
};

class AllocateRoomsTest : public ::testing::TestWithParam<AllocateRoomsTestCase> {};

TEST_P(AllocateRoomsTest, ReturnsExpectedAllocations) {
    auto result = allocateRooms(GetParam().customers);
    const auto& options = GetParam().expected_options;
    bool match = std::any_of(options.begin(), options.end(), [&](const std::vector<int>& opt){
        return opt == result;
    });
    EXPECT_TRUE(match) << "Result not in expected options. Result has size " << result.size();
}

INSTANTIATE_TEST_CASE_P(
    AllocateRoomsTests,
    AllocateRoomsTest,
    ::testing::Values(
        AllocateRoomsTestCase{{}, {{}}},
        // Simple placeholder cases; implementation pending
        AllocateRoomsTestCase{{{1, 2}, {2, 4}, {4, 4}}, {{1,2,1}, {2,1,2}}},
        AllocateRoomsTestCase{{{1, 5}, {2, 4}, {6, 8}, {7, 7}}, {{1,2,1,2}, {1,2,2,1}, {2,1,2,1},{2,1,1,2}}},
        AllocateRoomsTestCase{{{15, 22}, {2, 4}, {6, 9}, {3, 33}, {12, 21}},{{1,2,2,3,2}, {2,1,1,3,1}, {3,1,3,2,1}, {3,1,1,2,1}}}
    )
);
