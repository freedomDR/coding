#include<bits/stdc++.h>

using namespace std;

int fa[100005], n, m;

int findf(int f)
{
    if(f != fa[f])
        fa[f] = findf(fa[f]);
    return fa[f];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<tuple<int, int, int>> a;
    for(int i = 0; i < n; i++) fa[i] = i;
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back(make_tuple(x, y, z));
    }
    auto cmp = [](auto t1, auto t2)
    {
        return get<2>(t1) < get<2>(t2);
    };
    sort(a.begin(), a.end(), cmp);
    int cnt = 1, t = 0;
    for(auto &it:a)
    {
        int x = get<0>(it), y = get<1>(it);
        t = get<2>(it);
        if(findf(x)==findf(y)) continue;
        else fa[findf(x)] = fa[findf(y)];
        cnt++;
        if(cnt==n) break;
    }
    if(cnt == n) cout << t << endl;
    else cout << "-1" << endl;
    return 0;
}