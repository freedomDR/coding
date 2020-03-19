#include<bits/stdc++.h>

using namespace std;

//dp[i][0] = l r

int n, l, r, prel=1, prer=1, dpl, dpr;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        int t1, t2;
        t1 = t2 = 0x7f7f7f7f;
        t1 = min(abs(prel-r)+dpl, abs(prer-r)+dpr)+1+(r-l);
        t2 = min(abs(prel-l)+dpl, abs(prer-l)+dpr)+1+(r-l);
        dpl = t1; dpr = t2;
        prel = l;
        prer = r;
    }
    cout << min(n-l+dpl, n-r+dpr)-1 << endl;
    return 0;
}