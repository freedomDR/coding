#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;

long long power(long long a, long long b)
{
    long long res = 1;
    while(b>0)
    {
        if(b&1) res = (res*a)%mod;
        a = a*a%mod;
        b>>=1; 
    } 
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // C(m, n-1) * (n-1) (m!*(n-1))/((n-1)!*(m-n+1)!) % mod;
    long long ans = 1;
    for(int i = 1; i <= m; i++)
    {
        ans = (ans*i)%mod;
    }   
    long long r = 1;
    for(int i = 1; i <= n-1; i++) r=(r*i)%mod;
    for(int i = 1; i <= m-n+1; i++) r=(r*i)%mod;
    ans = ans*power(r, mod-2)%mod*(n-2)%mod;
    ans = ans*power(2, n-3)%mod;
    cout << ans << endl;
    return 0;
}