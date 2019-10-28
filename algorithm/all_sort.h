#include<bits/stdc++.h>

class AllSort
{
    public:
        AllSort();
        ~AllSort();
        static void quick_sort(std::vector<int> &arr, int l = -1, int r = -1);
        static void merge_sort(std::vector<int> &arr, int l = -1, int r = -1);
        static void heap_sort(std::vector<int> &arr);
        static void test_static();
};
