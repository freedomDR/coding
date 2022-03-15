#include <bits/stdc++.h>

using namespace std;

void b_sort(vector<int> & arr, int l, int r)
{
    cout << l << " " << r << endl;
    if(l >= r) return;
    int mid = (l+r)/2;
    int ll = l, rr = r;
    int mid_data = arr[mid];
    swap(arr[l], arr[mid]);
    while(ll < rr)
    {
        while(rr > ll && arr[rr] > mid_data) rr--;
        arr[ll] = arr[rr];
        while(ll < rr && arr[ll] <= mid_data) ll++;
        arr[rr] = arr[ll];
    }
    arr[ll] = mid_data;
    b_sort(arr, l, ll-1);
    b_sort(arr, ll+1, r);

}

int main()
{
    freopen("prac_b_sort.in", "r", stdin);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto & item : arr)
    {
        cin >> item;
    }
    b_sort(arr, 0, n-1);
    for (auto & item : arr)
    {
        cout << item << " ";
    }
    return 0;
}