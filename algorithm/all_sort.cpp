#include "all_sort.h"

void max_heap(std::vector<int>& arr, int pos, int limit)
{
    int dad = pos, son = dad*2+1;
    while(son < limit)
    {
        if(son+1 < limit && arr[son] < arr[son+1]) son++;
        if(arr[dad] > arr[son]) break;
        std::swap(arr[dad], arr[son]);
        dad = son; son = dad*2+1;
    }
}

void AllSort::heap_sort(std::vector<int>& arr)
{
    int len = arr.size();
    for(int i = len/2-1; i >= 0; i--)
    {
        max_heap(arr, i, len);
    }
    for(int i = len-1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        max_heap(arr, 0, i);
    }
}

void merge(std::vector<int>& arr, int l1, int r1, int l2, int r2)
{
    std::vector<int> temp(r2-l1+1);
    int p = 0, p1 = l1, p2 = l2;
    while(p1 <= r1 && p2 <= r2)
    {
        if(arr[p1] < arr[p2]) temp[p++] = arr[p1++];
        else temp[p++] = arr[p2++];
    }
    while(p1 <= r1) temp[p++] = arr[p1++];
    while(p2 <= r2) temp[p++] = arr[p2++];
    p = l1;
    for(auto v:temp) arr[p++] = v;
}

void AllSort::merge_sort(std::vector<int> &arr, int l, int r)
{
    if(l == -1 && r == -1) l = 0, r = arr.size()-1;
    if(l >= r) return;
    int mid = l + (r-l)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, mid, mid+1, r);
}

void AllSort::quick_sort(std::vector<int> &arr, int l, int r)
{
    if(l == -1 && r == -1) l = 0, r = arr.size()-1;
    if(l >= r) return;
    int flag = arr[l], ll = l, rr = r;
    while(ll < rr)
    {
        while(ll < rr && arr[rr] >= flag) rr--;
        arr[ll] = arr[rr];
        while(ll < rr && arr[ll] <= flag) ll++;
        arr[rr] = arr[ll];
    }
    arr[ll] = flag;
    quick_sort(arr, l, ll-1);
    quick_sort(arr, ll+1, r);
}

void AllSort::test_static()
{
    std::cout << "test static" << std::endl;
}
