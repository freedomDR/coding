#include<bits/stdc++.h>
using namespace std;

inline long long lowbit(long long x) {return x&(-x);}

void add(vector<long long> &t, int p, int v)
{
    while(p < (int)t.size())
    {
        t[p] += v;
        p += lowbit(p);
    }
}

long long sum(vector<long long>&t, int p)
{
    long long ans = 0;
    while(p > 0)
    {
        ans += t[p];
        p-=lowbit(p);
    }
    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> a(n+1), t(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] += a[i];
        if(i+lowbit(i) <= n)
            t[lowbit(i)+i] += t[i];
    }
    while(q--)
    {
        int o, i, j;
        cin >> o >> i >> j;
        if(o == 1)
        {
            add(t, i, j);
        }
        else
        {
            cout << (sum(t, j)-sum(t, i-1)) << endl;
            
        }
    }
    return 0;
}
