#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9+7;

int slove(int n)
{
    int ans = 0;
    int t = 1,l = 0,r = 0;
    while(n--)
    {
        int tt = l + r + t;
        int ll = r + t;
        int rr = l + t;
        t = tt % mod;
        l = ll % mod;
        r = rr % mod;
    }
    return (l+r+t)%mod;
}

int main()
{
    int n, nn;
    scanf("%d", &nn);
    while(nn--)
    {
        scanf("%d", &n);
        printf("%d\n",slove(n));
    }
    return 0;
}
