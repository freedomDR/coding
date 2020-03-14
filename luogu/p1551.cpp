#include<bits/stdc++.h>

using namespace std;

const int maxn = 5555;
int fa[maxn], n, m, p;

int get(int i)
{
    if(fa[i] == i) return i;
    else return fa[i] = get(fa[i]);
}

int main()
{
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        int fu = get(u), fv = get(v);
        fa[fu] = fv;
    }
    for(int i = 1; i <= p; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        if(get(a1)==get(a2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}