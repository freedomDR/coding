#include<bits/stdc++.h>
#include "all_sort.h"
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 9, -10, 11, 1, -5};
    /* AllSort::heap_sort(arr); */
    AllSort::quick_sort(arr);
    /* AllSort::merge_sort(arr); */
    for(int const v:arr) cout << v << endl;
    return 0;
}
