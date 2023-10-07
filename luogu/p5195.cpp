#include <bits/stdc++.h>
#include <tuple>
#include <utility>

int W, H;

int main()
{
    std::cin >> W >> H;
    std::vector<std::vector<int>> g(H, std::vector<int>(W));
    int st_x, st_y, end_x, end_y;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
        {
            std::cin >> g[i][j];
            if(g[i][j] == 2)
                st_x = i, st_y = j;
            if(g[i][j] == 3)
                end_x = i, end_y = j;
        }
    std::vector<std::vector<int>> f1(H, std::vector<int>(W, 1e9));
    std::vector<std::vector<int>> f2(H, std::vector<int>(W, 1e9));
    std::vector<std::pair<int, int>> offset;
    offset.push_back({-1, 0});
    offset.push_back({1, 0});
    offset.push_back({0, -1});
    offset.push_back({0, 1});
    // bfs
    std::vector<std::tuple<int, int>> q;
    int cnt = 0;
    q.push_back({st_x, st_y});
    f1[st_x][st_y] = 0;
    while(!q.empty())
    {
        std::vector<std::tuple<int, int>> tmp_q;
        cnt++;
        for(auto &v:q)
        {
            int x = std::get<0>(v), y = std::get<1>(v);
            for(auto &vv:offset)
            {
                int xx = x+vv.first, yy = y+vv.second;
                if(xx>=0&&xx<H&&yy>=0&&yy<W&&f1[xx][yy]==1e9&&g[xx][yy]!=1&&g[xx][yy]!=3)
                {
                    f1[xx][yy] = cnt;
                    tmp_q.push_back({xx, yy});
                }
            }
        }
        q = tmp_q;
    }

    cnt = 0;
    q.push_back({end_x, end_y});
    f2[end_x][end_y] = 0;
    while(!q.empty())
    {
        std::vector<std::tuple<int, int>> tmp_q;
        cnt++;
        for(auto &v:q)
        {
            int x = std::get<0>(v), y = std::get<1>(v);
            for(auto &vv:offset)
            {
                int xx = x+vv.first, yy = y+vv.second;
                if(xx>=0&&xx<H&&yy>=0&&yy<W&&f2[xx][yy]==1e9&&g[xx][yy]!=1)
                {
                    f2[xx][yy] = cnt;
                    tmp_q.push_back({xx, yy});
                }
            }
        }
        q = tmp_q;
    }

    int ans = 1e9;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
        {
            if(g[i][j] == 4)
            {
                ans = std::min(ans, f1[i][j]+f2[i][j]);
            }
        }

    std::cout << ans << std::endl;
    return 0;
}
