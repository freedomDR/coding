#include<bits/stdc++.h>

using namespace std;

int dx[5] = {0, -1, 0, 0, 1};
int dy[5] = {0, 0, -1, 1, 0};

int board[2005][2005], vis[2005][2005];
int t, n, m, ans, sx, sy, cx, cy;

void dfs(int x, int y)
{
    // cout << x << " " << y << endl;
    if(x == 0 || y == 0 || x > n || y > m)
        return;
    if(vis[x][y] > 1)
        return;
    if(vis[x][y] == 1)
    {
        cx = x; cy = y;
        vis[cx][cy] = 0;
        return;
    }
    int nx = x + dx[board[x][y]];
    int ny = y + dy[board[x][y]];
    vis[x][y] = 1;
    dfs(nx, ny);
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
        freopen("./codeforces/p1607F.in", "r", stdin);
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
        ans = 0;
        sx = 0; sy = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j] == 0)
                {
                    cx = -1; cy = -1;
                    dfs(i, j);
                    cout << i << " " << j << " " << vis[i][j] <<" "<< cx << " " << cy << endl;
                    if(cx != -1)
                    {
                        int tmp_d = vis[i][j], ii = i, jj = j;
                        while(ii != cx && jj != cy) 
                        {
                            tmp_d--;
                            int tmp_pos = board[ii][jj];
                            ii = ii + dx[tmp_pos];
                            jj = jj + dy[tmp_pos];
                        }
                        for(int k = 0; k < tmp_d+5; k++)
                        {
                            vis[cx][cy] = tmp_d;
                            int tmp_pos = board[cx][cy];
                            cx = cx + dx[tmp_pos];
                            cy = cy + dy[tmp_pos];
                        }
                    }
                }
            }
        }
        cout << sx << " " << sy << " " << vis[sx][sy] << endl;
        cout << vis[1][1] << " " << vis[1][2] << endl;
    }
    return 0;
}