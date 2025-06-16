#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int findMid(vector<ll> & arr, int l, int r) {
    ll flag = arr[l];
    int lp = l, rp = r;
    while (lp < rp) {
        while (lp<rp&&arr[rp]>flag) rp--;
        arr[lp] = arr[rp];
        while (lp<rp&&arr[lp]<=flag) lp++;
        arr[rp] = arr[lp];
    }
    arr[lp] = flag;
    if (lp == arr.size()/2) return arr[lp];
    if (lp > arr.size()/2) return findMid(arr, l, lp-1);
    else return findMid(arr, lp+1, r);
}

int main()
{
    // long long arr[n] 
    vector<ll> arr = {12,101,133,49,70,89,100};
    cout << findMid(arr, 0, arr.size()) << endl;
    return 0;
}