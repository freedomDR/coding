
#include<bits/stdc++.h>

using namespace std;
int n, e[105][105], ans = 0, vis[105];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> e[i][j];
    vis[1] = 1;
    int cur = 1;
    vector<int> cnt;
    cnt.push_back(1);
    while((int)cnt.size() < n)
    {
        int minn = INT_MAX, tmp;
        for(auto u:cnt)
            for(int i = 1; i <= n; i++)
            {
                if(!vis[i]&&i!=u&&e[u][i]<minn)
                {
                    minn = e[u][i];
                    tmp = i;
                }
            }
        ans += minn;
        cnt.push_back(tmp);
        vis[tmp] = 1;
    }
    cout << ans << endl;
    return 0;
}