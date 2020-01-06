#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
bool vis[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN], h[MAXN][MAXN];
int m, n;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, 1, -1, 0};

void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        if(h[xx][yy] >= h[x][y]) continue;
        if(!vis[xx][yy]) dfs(xx, yy);
        l[x][y] = min(l[x][y], l[xx][yy]);
        r[x][y] = max(r[x][y], r[xx][yy]);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> h[i][j];
    }
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            l[i][j] = j, r[i][j] = j;
    for(int i = 0; i < m; i++)
        if(!vis[0][i]) dfs(0, i);
    int cnt = 0;
    for(int i = 0; i < m; i++)
        if(vis[n-1][i]) cnt++;
    if(cnt != m)
    {
        cout << "0\n" << m-cnt << endl;
    }else
    {
        cout << "1" << endl;
        cnt = 0;
        int left = 0;
        while(left < m)
        {
            int maxr = 0;
            for(int i = 0; i < m; i++)
                if(l[0][i] <= left) maxr = max(maxr, r[0][i]);
            cnt++;
            left = maxr+1;
       }
        cout << cnt << endl;
    }
    return 0;
}
