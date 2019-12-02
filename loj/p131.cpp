#include<bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll lowbit(ll x) {return x&-x;}

void add(vector<ll> &d, int p, int v)
{
    while(p < (int)d.size())
    {
        d[p] += v; p += lowbit(p);
    }
}

ll getSum(vector<ll> &d, int p)
{
    ll ans = 0;
    while(p)
    {
        ans += d[p]; p -= lowbit(p);
    }
    return ans;
}



int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), d(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int tmp = a[i]-a[i-1];
        d[i] += tmp;
        int j = i + lowbit(i);
        if(j <= n) d[j] +=d[i];
    }
    while(q--)
    {
        int o; cin >> o;
        if(o == 1)
        {
            int l, r, v; cin >> l >> r >> v;
            add(d, l, v);if(r != n) add(d, r+1, -v);
        }
        else
        {
            int p; cin >> p;
            cout << getSum(d, p) << endl;
        }
    }
    return 0;
}
