cmake_minimum_required(VERSION 3.22)

# set the project name
project(Codewars)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add libraries
add_subdirectory(8kyu)
add_subdirectory(7kyu)

# add the executable
add_executable(Codewars main.cpp)

add_test(CodewarsTest main.cpp)

target_link_libraries(Codewars PUBLIC 8kyu)
target_link_libraries(Codewars PUBLIC 7kyu)

target_include_directories(Codewars PUBLIC
                          "${PROJECT_SOURCE_DIR}/8kyu"
                          "${PROJECT_SOURCE_DIR}/7kyu"
                          "${PROJECT_SOURCE_DIR}/8kyu/include"
                          "${PROJECT_SOURCE_DIR}/7kyu/include"
                          )
