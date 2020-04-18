#include<bits/stdc++.h>

using namespace std;

int fa[155], n, m;
int findf(int f)
{
    if(f != fa[f])
        fa[f] = findf(fa[f]);
    return fa[f];
}
int main()
{
    cin >> n >> m;
    vector<pair<int, int>> a, ans;
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j <= n; j++) fa[j] = j;
        int cnt = 1;
        for(int j = 0; j < m; j++)
        {
            if(j == i) continue;
            int x = a[j].first, y = a[j].second;
            if(findf(x) == findf(y)) continue;
            else fa[findf(x)] = findf(y);
            cnt++;
        }
        if(cnt == n-1) ans.push_back(a[i]);
    }
    for(auto &it:ans)
    {
        if(it.first > it.second) swap(it.first, it.second);
    }
    sort(ans.begin(), ans.end());
    for(auto &it:ans)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}