#include<bits/stdc++.h>

using namespace std;

int a[100], n, b[100];

void quick_sort(int l, int r)
{
    if(r<=l) return;
    int flag = a[l], ll = l, rr = r;
    while(l < r)
    {
        while(l<r&&a[r]>=flag)r--;
        a[l]=a[r];
        while(l<r&&a[l]<=flag)l++;
        a[r] = a[l];
    }
    a[l] = flag;
    quick_sort(ll, l-1);
    quick_sort(l+1, rr);
}

void merge(int l1, int r1, int l2, int r2)
{
    int len = 0;
    int i1 = l1, i2 = l2;
    while(i1 <= r1 && i2 <= r2)
    {
        if(a[i1] < a[i2]) b[len++] = a[i1++];
        else b[len++] = a[i2++];
    }
    while(i1 <= r1) b[len++] = a[i1++];
    while(i2 <= r2) b[len++] = a[i2++];
    for(int i = 0; i < len; i++)
    {
        a[l1++] = b[i];
    }
}

void merge_sort(int l, int r)
{
    if(l >= r) return;
    int mid = (l+r)/2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, mid, mid+1, r);
}

void max_heap(int pos, int r)
{
    int dad = pos, son = pos*2+1;
    while(son < r)
    {
        if(son+1 < r && a[son] < a[son+1]) son++;
        if(a[dad]>a[son]) break;
        swap(a[dad], a[son]);
        dad = son;
        son = dad*2+1; 
    }
}

void heap_sort(int l, int r)
{
    for(int i = n/2-1; i >= 0; i--)
    {
        max_heap(i, n);
    }
    for(int i = n-1; i > 0; i--)
    {
        swap(a[0], a[i]);
        max_heap(0, i);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    /* quick_sort(0, n-1); */
    /* merge_sort(0, n-1); */
    heap_sort(0, n-1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
