#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll powmod(ll v, ll sum)
{
    if(sum == 0) return 1;
    if(sum&1) return v*powmod(v, sum-1)%MOD;
    return powmod(v*v%MOD, sum/2);
}

int main()
{
    ll x, n, ans = 1;
    cin >> x >> n;
    vector<ll> prime;
    for(ll i = 2; i*i <= x; i++)
    {
        if(x%i != 0) continue;
        prime.push_back(i);
        while(x%i == 0) x /= i;
    }
    if(x != 1) prime.push_back(x);
    for(auto& v:prime)
    {
        ll sum = 0;
        ll tmp = n/v;
        while(tmp)
        {
            sum += tmp;
            tmp /= v;
        }
        ans *= powmod(v, sum);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
