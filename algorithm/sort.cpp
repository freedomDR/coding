#include<bits/stdc++.h>
using namespace std;

void quickSort1(vector<int>& arr, int l, int r) 
{
    if(l >= r) return;
    int key = arr[l];
    int ll = l, rr = r;
    while(ll < rr) 
    {
        while(ll < rr && arr[rr] > key) rr--;
        arr[ll] = arr[rr];
        while(ll < rr && arr[ll] <= key) ll++;
        arr[rr] = arr[ll];
    }
    arr[ll] = key;
    quickSort1(arr, l, ll-1);
    quickSort1(arr, ll+1, r);
}

void quickSort2(vector<int>& arr, int l, int r) 
{
    if(l < r)
    {
        int key = arr[r], p = l;
        for(int i = l; i < r; i++)
        {
            if(arr[i] < key)
            {
                swap(arr[i], arr[p]);
                p++;
            }
        }
        swap(arr[p], arr[r]);
        quickSort2(arr, l, p-1);
        quickSort2(arr, p+1, r);
    }
}

void heap(vector<int>& arr, int start, int end)
{
    int dad = start, son = start*2+1;
    while(son <= end)
    {
        if(son+1 <= end && arr[son] < arr[son+1])
            son++;
        if(arr[dad] > arr[son])
            return;
        else
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad*2+1;
        }
    }
}

void heapSort(vector<int>& arr)
{
    int len = arr.size();
    for(int i = len/2 - 1; i >= 0; i--)
    {
        heap(arr, i, len-1);
    }
    for(int i = len-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heap(arr, 0, i-1);
    }
}

int main()
{
    vector<int> arr = {1,2,0,5,9,1000,8,0,9,11,3,1};
    heapSort(arr);
    for(auto& it:arr) cout << it << endl;

}

