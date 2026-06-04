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
add_subdirectory(6kyu)
# ------------------------------------------------------------
# Combined CodeWars library
# ------------------------------------------------------------
add_library(CodeWars INTERFACE)

target_link_libraries(CodeWars
    INTERFACE
        8kyu
        7kyu
        6kyu
)

target_include_directories(CodeWars
    INTERFACE
        "${PROJECT_SOURCE_DIR}/8kyu/include"
        "${PROJECT_SOURCE_DIR}/7kyu/include"
        "${PROJECT_SOURCE_DIR}/6kyu/include"
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
        6kyu/tests/test_midiFiles.cpp
        6kyu/tests/test_snakeEye.cpp
        7kyu/tests/test_cigarStringsEasy.cpp
        7kyu/tests/test_convertTheScore.cpp
        7kyu/tests/test_countCodePoints.cpp
        7kyu/tests/test_everyPossibleSumOfTwoDigits.cpp
        7kyu/tests/test_findLineup.cpp
        7kyu/tests/test_fixStringCase.cpp
        7kyu/tests/test_jumbler.cpp
        7kyu/tests/test_leonardoNumbers.cpp
        7kyu/tests/test_offloadYourWork.cpp
        7kyu/tests/test_queueTimeCounter.cpp
        7kyu/tests/test_redacted.cpp
        7kyu/tests/test_removeDuplicateWords.cpp
        7kyu/tests/test_smoothNumbers.cpp
        7kyu/tests/test_stringPacketBasedCommunication.cpp
        7kyu/tests/test_subArrayElementsSum.cpp
        7kyu/tests/test_sumOfABeach.cpp
        7kyu/tests/test_tramCapacity.cpp
        8kyu/tests/test_returnLocation.cpp
    )

    target_link_libraries(CodeWarsTests
        PRIVATE
            CodeWars
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(CodeWarsTests)
endif()
