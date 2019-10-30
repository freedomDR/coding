cmake_minimum_required (VERSION 2.8)
PROJECT(algorithm)

add_executable(test_sort sort_test.cpp all_sort.h all_sort.cpp)
install(TARGETS test_sort DESTINATION bin)

add_executable(test_b_tree b_tree.h b_tree.cpp travel_tree_test.cpp)
install(TARGETS test_b_tree DESTINATION bin)
enable_testing()
add_test(test_run test_sort)
add_test(test_tree test_b_tree)
set_tests_properties(test_tree
    PROPERTIES PASS_REGULAR_EXPRESSION "2 4 3 7 9 8 5"
    )

