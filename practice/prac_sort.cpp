#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int> &arr, int l, int r)
{
    if(l>=r) return;
    swap(arr[l], arr[(l+r)/2]);
    int flag = arr[l], ll = l, rr = r;
    while(l<r)
    {
        while(l<r&&arr[r]>=flag) r--;
        arr[l] = arr[r];
        while(l<r&&arr[l]<=flag) l++;
        arr[r] = arr[l];
    }
    arr[l] = flag;
    quick_sort(arr, ll, l);
    quick_sort(arr, l+1, rr);
}

void max_heap(vector<int> &arr, int p, int r)
{
    int dad = p, son = p*2+1;
    while(son < r)
    {
        if(son+1 < r && arr[son] < arr[son+1]) son++;
        if(arr[dad] > arr[son]) return;
        swap(arr[dad], arr[son]);
        dad = son;
        son = dad*2+1;
    }
}

void heap_sort(vector<int> &arr)
{
    int len = arr.size();
    for(int i = len/2-1; i >= 0; i--)
    {
        max_heap(arr, i, len);
    }
    for(int i = len-1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        max_heap(arr, 0, i);
    }
}

void merge(vector<int> &arr, int l1, int r1, int l2, int r2)
{
    vector<int> tmp;
    int p1 = l1, p2 = l2;
    while(p1 <= r1 && p2 <= r2)
    {
        if(arr[p1]>arr[p2]) tmp.push_back(arr[p2++]);
        else tmp.push_back(arr[p1++]);
    }
    while(p1 <= r1) tmp.push_back(arr[p1++]);
    while(p2 <= r2) tmp.push_back(arr[p2++]);
    p1 = l1;
    for(auto it:tmp) arr[p1++] = it;
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if(l>=r) return;
    int mid = (l+r)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, mid, mid+1, r);
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    vector<int> arr;
    for(int i = 0; i < 20; i++)
    {
        arr.push_back(dis(gen));
    }
    cout << "origin data: ";
    for(auto &it:arr) cout << it << " ";
    cout << endl;

    // quick_sort(arr, 0, arr.size()-1);
    // heap_sort(arr);
    merge_sort(arr, 0, arr.size()-1);

    cout << "sort data: ";
    for(auto &it:arr) cout << it << " ";
    cout << endl;
    return 0;
}