#include<bits/stdc++.h>
using namespace std;

int g[10][10], n, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main()
{
    cin >> n;
    int v = 1, x = 0, y = 0, p = 0;
    while(v <= n*n)
    {
        g[x][y] = v;
        v++;
        int xx = x+dx[p], yy = y+dy[p];
        if(xx<0||xx>=n||yy<0||yy>=n||g[xx][yy]!=0)
        {
            p++;
            p %= 4;
            xx = x+dx[p]; yy = y+dy[p];
        }
        x = xx; y = yy;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%3d", g[i][j]);
        printf("\n");
    }
    return 0;
}
