cmake_minimum_required(VERSION 3.10)

# set the project name
project(coding)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_subdirectory(luogu)
# add_subdirectory(codeforces)
# add_subdirectory(practice)
add_subdirectory(leetcode)
add_executable(test_fmt test_fmt.cpp)
target_link_libraries(test_fmt fmt)
add_executable(test_2 test_2.cpp)
target_link_libraries(test_2 fmt)
