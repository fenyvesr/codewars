cmake_minimum_required(VERSION 3.22)

# Set the project name
project(CodeWars LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# Project libraries
# ------------------------------------------------------------
add_subdirectory(8kyu)
add_subdirectory(7kyu)

# ------------------------------------------------------------
# Combined CodeWars library
# ------------------------------------------------------------
add_library(CodeWars INTERFACE)

target_link_libraries(CodeWars
    INTERFACE
        8kyu
        7kyu
)

target_include_directories(CodeWars
    INTERFACE
        "${PROJECT_SOURCE_DIR}/8kyu"
        "${PROJECT_SOURCE_DIR}/7kyu"
        "${PROJECT_SOURCE_DIR}/8kyu/include"
        "${PROJECT_SOURCE_DIR}/7kyu/include"
)

# ------------------------------------------------------------
# Unit tests with GoogleTest
# ------------------------------------------------------------
include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )

    # Needed for Windows/MSVC runtime compatibility
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(CodeWarsTests
        tests/test_main.cpp
        tests/7kyu/test_cigarStringsEasy.cpp
        tests/7kyu/test_convertTheScore.cpp
        tests/7kyu/test_everyPossibleSumOfTwoDigits.cpp
        tests/7kyu/test_fixStringCase.cpp
        tests/7kyu/test_leonardoNumbers.cpp
        tests/7kyu/test_offloadYourWork.cpp
        tests/7kyu/test_queueTimeCounter.cpp
        tests/7kyu/test_redacted.cpp
        tests/7kyu/test_removeDuplicateWords.cpp
        tests/7kyu/test_smoothNumbers.cpp
        tests/7kyu/test_stringPacketBasedCommunication.cpp
        tests/7kyu/test_subarrayElementsSum.cpp
        tests/7kyu/test_sumOfABeach.cpp
        tests/7kyu/test_tramCapacity.cpp
        tests/8kyu/test_returnLocation.cpp
    )

    target_link_libraries(CodeWarsTests
        PRIVATE
            CodeWars
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(CodeWarsTests)
endif()
