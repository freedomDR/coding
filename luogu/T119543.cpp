#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        int cnt = 0;
        int l, r;
        //i < j
        l = 1; r = (n-1)/2+1;
        while(l<r)
        {
            int mid = (l+r)/2;
            int i = mid, j = n-i;
            if((i/j+(j-1)/i+1)>m) l = mid+1;
            else r = mid;
        }
        int l1 = l;
        l = 1; r = (n-1)/2+1;
        while(l<r)
        {
            int mid = (l+r)/2;
            int i = mid, j = n-i;
            if((i/j+(j-1)/i+1)>=m) l = mid+1;
            else r = mid;
        }
        int r1 = l-1;
        if(r1>=l1) cnt+=r1-l1+1;
        //i>=j
        l = (n-1)/2+1; r = n;
        while(l<r)
        {
            int mid = (l+r)/2;
            int i = mid, j = n-i;
            if((i/j+(j-1)/i+1)<m) l = mid+1;
            else r = mid;
        }
        l1 = l;
        l = (n-1)/2+1; r = n;
        while(l<r)
        {
            int mid = (l+r)/2;
            int i = mid, j = n-i;
            if((i/j+(j-1)/i+1)<=m) l = mid+1;
            else r = mid;
        }
        r1 = l-1;
        if(r1>=l1) cnt+=r1-l1+1;
        cout << cnt << endl;
    }
    return 0;
}