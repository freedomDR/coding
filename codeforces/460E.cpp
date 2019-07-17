#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll pow(ll a, ll p, ll mod)
{
    ll res = 1;
    while(p){
        if(p&1)
            res = res*a%mod;
        p >>= 1;
        a = a*a%mod;
    }
    return res;
}

int main()
{
    ll a, b, p;
    ll x;
    cin>>a>>b>>p>>x;
    if(p == 2){
        cout<<x/2+(x%2==1)<<endl;
        return 0;
    }
    ll ans = 0;
    ll mul = p*(p-1);
    for(ll j = 0; j <= p-2; j++){
        ll y = b*pow(pow(a, j, p), p-2, p)%p;
        ll min_n = (j*p*pow(p, p-3, p-1)%mul+y*(p-1)*pow(p-1,p-2,p)%mul)%mul;
        ans += x/mul+(x%mul >= min_n);
    }
    cout<<ans<<endl;
    return 0;
}
