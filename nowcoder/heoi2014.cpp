#include<iostream>
#include<vector>

using namespace std;

long long n, sa, sb, sc, sd, mod, tmp;
long long f(long long x)
{
    long long ret = sd;
    ret = (ret+(sc*x)%mod)%mod;
    ret = (ret+((sb*x)%mod*x))%mod;
    ret = (ret+(((sa*x)%mod*x)%mod*x)%mod)%mod;
    return ret;
}

int main()
{
    cin >> n >> sa >> sb >> sc >> sd >> tmp >> mod;
    sa %= mod; sb %= mod; sc %= mod; sd %= mod; tmp %= mod;
    vector<long long> a(n+1), rmin(n+1, 1000000000);
    a[1] = tmp;
    for(int i = 2; i <= n; i++)
    {
        a[i] = (f(a[i-1])%mod+f(a[i-2])%mod) % mod;
    }
    rmin[n] = a[n];
    long long ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] > rmin[i+1]) ans = max(ans, (a[i]-rmin[i+1]-1)/2+1);
        rmin[i] = min(a[i], rmin[i+1]);
    }
    cout << ans << endl;
    return 0;
}