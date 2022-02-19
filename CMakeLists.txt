cmake_minimum_required(VERSION 3.10)

# set the project name
project(coding)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(luogu)
add_subdirectory(codeforces)
add_subdirectory(test)
