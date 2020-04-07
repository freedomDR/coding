#include<bits/stdc++.h>

using namespace std;

long long n, m, a[155], tmp[155], mod=998244353, pre[155];

long long powmod(long long a, long long b)
{
    long long ret = 1;
    while(b>0)
    {
        if(b&1) ret=ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    for(int i = 1; i <= 150; i++)
    {
        pre[i] = powmod(i, mod-2);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        long long sums = 0;
        bool eee = true;
        for(int j = 1; j <= n; j++)
        {
            sums += a[j];
            tmp[j] = (sums%mod*pre[j])%mod;
            if(tmp[j] != a[j]) eee = false;
        }
        if(eee) break;
        for(int j = 1; j <= n; j++) a[j] = tmp[j];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}