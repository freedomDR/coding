#include<bits/stdc++.h>

using namespace std;

int n, m, k, g[100][100], sums;
int dx[8]={2, 2, -2, -2, 1, -1, 1, -1}, dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
int dxx[8]={1, 1, -1, -1, 1, -1, 1, -1}, dyy[8] = {1, -1, 1, -1, 1, 1, -1, -1};
int dxxx[8]={1, 1, -1, -1, 0, 0, 0, 0}, dyyy[8] = {0, 0, 0, 0, 1, 1, -1, -1};

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        x--;y--;
        if(g[x][y]==1) continue;
        bool can = true;
        for(int j = 0; j < 8; j++)
        {
            int xx = x+dx[j], yy = y+dy[j];
            if(xx>=0&&xx<n&&yy>=0&&yy<m)
            {
                if(g[xx][yy]==0)continue;
                if(g[x+dxx[j]][y+dyy[j]]==0||g[x+dxxx[j]][y+dyyy[j]]==0) can = false;
            }
        }
        if(can){g[x][y]=1;sums++;}
    }
    cout << sums << endl;
    return 0;
}