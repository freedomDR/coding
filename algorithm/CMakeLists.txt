cmake_minimum_required (VERSION 2.8)
PROJECT(algorithm)

add_executable(test_sort sort_test.cpp all_sort.h all_sort.cpp)
install(TARGETS test_sort DESTINATION bin)

enable_testing()
add_test(test_run test_sort)

