#include<bits/stdc++.h>
int t[3][3];
int ss[3][3];
/* int dx[4] = {0, 1, -1, 0}; */
/* int dy[4] = {1, 0, 0, -1}; */
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
std::string s;
std::string st = "123804765";

int check()
{
    int diff = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(t[i][j]!=ss[i][j])
                diff++;
        }
    }
    return diff;
}

bool dfs(int x, int y, int pre, int depth, int cur_depth)
{
    if(depth == cur_depth)
    {
        if(check()==0) return true;
        else return false;
    }
    if(check()>depth-cur_depth+1) return false;
    int ans = false;
    for(int i = 0; i < 4 && !ans; i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||ny<0||nx>2||ny>2) continue;
        if(pre!=-1&&pre!=i&&pre%2==i%2) continue;
        std::swap(ss[x][y], ss[nx][ny]);
        ans |= dfs(nx, ny, i, depth, cur_depth+1);
        std::swap(ss[x][y], ss[nx][ny]);
    }
    return ans;
}

int main()
{
    std::cin >> s;
    int x, y;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            ss[i][j] = s[i*3+j]-'0';
            if(ss[i][j] == 0)
                x = i, y = j;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            t[i][j] = st[i*3+j]-'0';
        }
    }
    if(check()==0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    int depth = 1;
    while(true)
    {
        if(dfs(x, y, -1, depth, 0))
            break;
        depth++;
    }
    std::cout << depth << std::endl;

    return 0;
}
