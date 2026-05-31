cmake_minimum_required(VERSION 3.22)

# set the project name
project(CodeWars)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add libraries
add_subdirectory(8kyu)
add_subdirectory(7kyu)

# add the executable
add_executable(CodeWars main.cpp)

# Enable testing for the project
enable_testing()
# add the test executable
add_test(CodeWarsTest CodeWars)

target_link_libraries(CodeWars PUBLIC 8kyu)
target_link_libraries(CodeWars PUBLIC 7kyu)

target_include_directories(CodeWars PUBLIC
                          "${PROJECT_SOURCE_DIR}/8kyu"
                          "${PROJECT_SOURCE_DIR}/7kyu"
                          "${PROJECT_SOURCE_DIR}/8kyu/include"
                          "${PROJECT_SOURCE_DIR}/7kyu/include"
                          )
