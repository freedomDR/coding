#include<bits/stdc++.h>

using namespace std;

int dx[5] = {0, -1, 0, 0, 1};
int dy[5] = {0, 0, -1, 1, 0};

int board[2005][2005], vis[2005][2005], f[2005][2005];
int t, n, m, ans, sx, sy;

void dfs(int x, int y)
{
    // cout << x << " " << y << endl;
    if(x == 0 || y == 0 || x > n || y > m || f[x][y])
        return;
    int nx = x + dx[board[x][y]];
    int ny = y + dy[board[x][y]];
    f[x][y] = 1;
    dfs(nx, ny);
    //f[x][y] = 0;
    vis[x][y] = vis[nx][ny]+1;
    if(vis[x][y] > ans)
    {
        sx = x;
        sy = y;
        ans = max(ans, vis[x][y]);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("./codeforces/p1697F.in", "r", stdin);
    #endif
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                char c; cin >> c;
                if(c == 'L') board[i][j] = 2;
                else if(c == 'R') board[i][j] = 3;
                else if(c == 'U') board[i][j] = 1;
                else board[i][j] = 4;
            }
        }
        memset(vis, 0, sizeof vis);
        memset(f, 0, sizeof f);
        ans = 0;
        sx = 0; sy = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j] == 0)
                    dfs(i, j);
            }
        }
        cout << sx << " " << sy << " " << vis[sx][sy] << endl;
    }
    return 0;
}