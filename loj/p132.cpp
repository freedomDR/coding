#include<bits/stdc++.h>
using namespace std;

using ll = long long;
inline int lb(int p) 
{
    return p & -p;
}

void add(vector<ll> &a, int p, ll v)
{
    while(p < (int)a.size())
    {
        a[p] += v; p += lb(p);
    }
}

ll getSum(vector<ll> &a, int p)
{
    ll sum = 0;
    while(p > 0)
    {
        sum += a[p]; p -= lb(p);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), pre(n+1), d1(n+2), d2(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    while(q--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l, r, v; cin >> l >> r >> v;
            add(d1, l, v); add(d2, l, 1ll*v*l);
            add(d1, r+1, -v);
            add(d2, r+1, 1ll*-v*(r+1));
        }
        else
        {
            int l, r; cin >> l >> r;
            cout << (pre[r]+getSum(d1, r)*(r+1)-getSum(d2,r))-(pre[l-1]+getSum(d1,l-1)*l-getSum(d2,l-1)) << endl;
        }
    }
    return 0;
}
