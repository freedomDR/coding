#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
    dfs(r0,c0, color, grid[r0][c0], visit, grid);
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(visit[i][j])
            {
                if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1)
                {
                    grid[i][j] = color;
                    continue;
                }
                if(visit[i-1][j]&&visit[i+1][j]&&visit[i][j-1]&&visit[i][j+1]) continue;
                else grid[i][j] = color;
            }
        }
    }
    return grid;
}

void dfs(int i, int j, int color, int flag, vector<vector<bool>>& visit, vector<vector<int>>& grid) {
    if(i < 0 || i == visit.size() || j < 0 || j == visit[0].size() || visit[i][j] || grid[i][j] != flag) return;
    visit[i][j] = true;
    dfs(i+1, j, color, flag, visit, grid);
    dfs(i-1, j, color, flag, visit, grid);
    dfs(i, j+1, color, flag, visit, grid);
    dfs(i, j-1, color, flag, visit, grid);
}
int main()
{
    return 0;
}
