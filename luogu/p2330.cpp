#include<bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, c;
}e[100100];

int fa[333], n, m;

int get(int i)
{
    if(i != fa[i])
        fa[i] = get(fa[i]);
    return fa[i];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].c;
    sort(e+1, e+m+1, [](Edge &e1, Edge &e2) {return e1.c < e2.c;});
    int l = e[1].c, r = e[m].c;
    while(l < r)
    {
        int mid = (l+r)/2;
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= m; i++)
        {
            if(e[i].c > mid) break;
            int u = e[i].u, v = e[i].v;
            int fu = get(u), fv = get(v);
            if(fu != fv) fa[fu] = fv;
        }
        bool ok = true;
        for(int i = 2; i <= n; i++)
        {
            if(get(i) != get(i-1)) ok = false;
        }
        if(ok)
            r = mid;
        else
            l = mid+1;
    }
    cout << n-1 << " " << l << endl;
    return 0;
}