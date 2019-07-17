#include <bits/stdc++.h>

using namespace std;
const int N = 100100;
int a[N];

void quick_sort(int l, int r)
{
    if(l >= r) return;
    swap(a[l], a[(l+r)/2]);
    int t = a[l], ll = l, rr = r;
    while(l < r)
    {
        while(l < r && a[r] >= t) r--;
        if(l < r) a[l++] = a[r];
        while(l < r && a[l] <= t) l++;
        if(l < r) a[r--] = a[l];
    }
    a[l] = t;
    quick_sort(ll, l-1);
    quick_sort(l+1, rr);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, pos = 0;
    map<int, int> count;
    cin>>n;
    for(int i = 0; i < n; i++) 
    {
        int v; cin>>v;
        if(count[v] == 0) a[pos++] = v;
        count[v]++;
    }
    quick_sort(0, pos-1);
    /* sort(a, a+n); */
    for(int i = 0; i < pos; i++) 
    {
        for(int j = 0; j < count[a[i]]; j++)
            cout<<a[i]<<" ";
    }
    return 0;
}
