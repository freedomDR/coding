#include<bits/stdc++.h>

using namespace std;

int a[500010], n, m;
inline int lowbit(int x)
{
    return x&(-x);
}

void add(int p, int k)
{
    while(p <= n)
    {
        a[p] += k;
        p = p+lowbit(p);
    }
}

int getSum(int p)
{
    int ret = 0;
    while(p >= 1)
    {
        ret += a[p];
        p = p-lowbit(p);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        a[i] += v;
        int j = i+lowbit(i);
        if(j <= n) a[j] += a[i];        
    }
    for(int i = 0; i < m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
        {
            add(x, y);
        }else
        {
            cout << getSum(y)-getSum(x-1) << endl;
        }
        
    }
    return 0;
}