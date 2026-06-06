#include <gtest/gtest.h>

#include "allocateRooms.h"

#include <algorithm> /* Needed for std::any_of */
#include <fstream>   /* Needed for std::ifstream */
#include <sstream>   /* Needed for std::istringstream */
#include <stdexcept> /* Needed for std::runtime_error */
#include <string>    /* Needed for std::string */
#include <vector>    /* Needed for std::vector */

struct AllocateRoomsTestCase {
    std::vector<std::vector<int>> customers;
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

namespace {

std::string sourceDirectory() {
    const std::string file{__FILE__};
    const auto pos = file.find_last_of("/\\");
    return pos == std::string::npos ? std::string{} : file.substr(0, pos);
}

std::ifstream openDataFile(const std::vector<std::string>& candidates) {
    for (const auto& path : candidates) {
        std::ifstream in{path};
        if (in) return in;
    }

    throw std::runtime_error{"Could not open allocateRooms_cases.txt"};
}

std::ifstream openDataFile() {
    return openDataFile({
        "allocateRooms_cases.txt",
        "6kyu/tests/data/allocateRooms_cases.txt",
        sourceDirectory() + "/data/allocateRooms_cases.txt",
        sourceDirectory() + "/allocateRooms_cases.txt"
    });
}

std::string nextToken(std::istream& in) {
    std::string token;
    while (in >> token) {
        if (!token.empty() && token[0] == '#') {
            std::string ignored;
            std::getline(in, ignored);
            continue;
        }
        return token;
    }
    throw std::runtime_error{"Unexpected end of allocateRooms_cases.txt"};
}

void expectToken(std::istream& in, const std::string& expected) {
    const auto token = nextToken(in);
    if (token != expected)
        throw std::runtime_error{"Expected token '" + expected + "', got '" + token + "'"};
}

std::vector<AllocateRoomsTestCase> loadAllocateRoomsCases() {
    auto in = openDataFile();

    expectToken(in, "COUNT");
    const auto case_count = static_cast<std::size_t>(std::stoul(nextToken(in)));

    std::vector<AllocateRoomsTestCase> cases;
    cases.reserve(case_count);

    for (std::size_t case_idx{}; case_idx < case_count; ++case_idx) {
        expectToken(in, "CASE");
        expectToken(in, "CUSTOMERS");
        const auto customer_count = static_cast<std::size_t>(std::stoul(nextToken(in)));

        AllocateRoomsTestCase tc;
        tc.customers.reserve(customer_count);
        for (std::size_t i{}; i < customer_count; ++i) {
            tc.customers.push_back({
                std::stoi(nextToken(in)),
                std::stoi(nextToken(in))
            });
        }

        expectToken(in, "OPTIONS");
        const auto option_count = static_cast<std::size_t>(std::stoul(nextToken(in)));
        tc.expected_options.reserve(option_count);

        for (std::size_t option_idx{}; option_idx < option_count; ++option_idx) {
            expectToken(in, "VALUES");
            const auto value_count = static_cast<std::size_t>(std::stoul(nextToken(in)));

            std::vector<int> option;
            option.reserve(value_count);
            for (std::size_t value_idx{}; value_idx < value_count; ++value_idx)
                option.push_back(std::stoi(nextToken(in)));

            tc.expected_options.push_back(std::move(option));
        }

        expectToken(in, "END");
        cases.push_back(std::move(tc));
    }

    return cases;
}

const std::vector<AllocateRoomsTestCase>& allocateRoomsTestCases() {
    static const auto cases = loadAllocateRoomsCases();
    return cases;
}

} // namespace


TEST(AllocateRoomsParserTest, OpenDataFileThrowsForMissingFile) {
    EXPECT_THROW(
        static_cast<void>(openDataFile({"definitely_missing_allocateRooms_cases.txt"})),
        std::runtime_error
    );
}

TEST(AllocateRoomsParserTest, NextTokenThrowsOnEmptyInput) {
    std::istringstream in{};
    EXPECT_THROW(static_cast<void>(nextToken(in)), std::runtime_error);
}

TEST(AllocateRoomsParserTest, NextTokenThrowsOnCommentOnlyInput) {
    std::istringstream in{"# only a comment"};
    EXPECT_THROW(static_cast<void>(nextToken(in)), std::runtime_error);
}

TEST(AllocateRoomsParserTest, ExpectTokenThrowsOnWrongToken) {
    std::istringstream in{"CUSTOMERS"};
    EXPECT_THROW(expectToken(in, "COUNT"), std::runtime_error);
}

TEST(AllocateRoomsParserTest, ExpectTokenThrowsOnEmptyInput) {
    std::istringstream in{};
    EXPECT_THROW(expectToken(in, "COUNT"), std::runtime_error);
}

class AllocateRoomsTest : public ::testing::TestWithParam<AllocateRoomsTestCase> {};

TEST_P(AllocateRoomsTest, ReturnsExpectedAllocations) {
    const auto result = allocateRooms(GetParam().customers);
    const auto& options = GetParam().expected_options;
    const bool match = std::any_of(options.begin(), options.end(), [&](const std::vector<int>& opt) {
        return opt == result;
    });

    EXPECT_TRUE(match) << "Result not in expected options. Result has size " << result.size();
}

INSTANTIATE_TEST_SUITE_P(
    AllocateRoomsTests,
    AllocateRoomsTest,
    ::testing::ValuesIn(allocateRoomsTestCases())
);
