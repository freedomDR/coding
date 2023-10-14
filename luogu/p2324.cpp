#include <bits/stdc++.h>
#include <chrono>
#include <thread>

int t[5][5];
int target[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1},
    {0, 0, -1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, -2, 2, 1, -1, 1, -1};

int diff()
{
    int res = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(t[i][j] != target[i][j])
                res++;
        }
    }
    return res;
}

bool dfs(int x, int y, int step, int depth, int pre)
{
    /* std::cout << x << " " << y << " " << step << " " << depth << " " << pre << std::endl; */
    /* std::this_thread::sleep_for(std::chrono::milliseconds(200)); */
    if(depth == step)
    {
        if(diff()==0) return true;
        else return false;
    }
    if(diff()>depth-step+1) return false;
    int ans = false;
    for(int i = 0; i < 8 && !ans; i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||ny<0||nx>4||ny>4||pre==nx*5+ny) continue;
        std::swap(t[nx][ny], t[x][y]);
        ans |= dfs(nx, ny, step+1, depth, nx*5+ny);
        std::swap(t[nx][ny], t[x][y]);
    }
    return ans;
}

void slove()
{
    int st_x, st_y;
    for(int i = 0; i < 5; i++)
    {
        std::string s; std::cin >> s;
        for(int j = 0; j < 5; j++)
        {
            if(s[j] == '*')
                t[i][j] = -1;
            else
                t[i][j] = s[j]-'0';
            if(t[i][j] == -1)
                st_x = i, st_y = j;
        }
    }
    int depth = 0;
    while(++depth <= 15)
    {
        bool res = dfs(st_x, st_y, 0, depth, -1);
        if(res)
        {
            std::cout << depth << std::endl; 
            return;
        }
    }
    std::cout << -1 << std::endl;
}

int main()
{
    int T; std::cin >> T;
    while(T--)
    {
        slove();
    }
    return 0;
}
