/*
 * 最标准的bfs了吧
 */
#include <bits/stdc++.h>

using namespace std;

void dfs(int x, int y, int fx, int fy, int& ans, int N, int M, vector<vector<bool>>& visit, vector<vector<int>>& grid)
{
    if(x < 0 || x == M || y < 0 || y == N || visit[x][y] || !grid[x][y]) return;
    if(x == fx && y == fy) {++ans; return;}
    visit[x][y] = true;
    dfs(x+1, y, fx, fy, ans, N, M, visit, grid);
    dfs(x-1, y, fx, fy, ans, N, M, visit, grid);
    dfs(x, y+1, fx, fy, ans, N, M, visit, grid);
    dfs(x, y-1, fx, fy, ans, N, M, visit, grid);
    visit[x][y] = false;
}

int main()
{
    int N, M, T, sx, sy, fx, fy;
    cin>>N>>M>>T>>sx>>sy>>fx>>fy;
    --sx;--sy;--fx;--fy;
    vector<vector<int>> grid(N, vector<int>(M, 1));
    for(int i = 0; i < T; i++)
    {
        int x, y; cin>>x>>y;
        grid[--x][--y] = 0;
    }
    int ans = 0;
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    dfs(sx, sy, fx, fy, ans, N, M, visit, grid);
    cout<<ans<<endl;
    return 0;
}
