#include<bits/stdc++.h>

using namespace std;

struct node
{
    int h, v;
    int l, r;
}mx[505][505];

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    // cout << x << " " << y << endl;
    mx[x][y].v = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        if(mx[nx][ny].h >= mx[x][y].h)
            continue;
        if(!mx[nx][ny].v) dfs(nx, ny);
        mx[x][y].l = min(mx[x][y].l, mx[nx][ny].l);
        mx[x][y].r = max(mx[x][y].r, mx[nx][ny].r);
    }    
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> mx[i][j].h;
            mx[i][j].l = mx[i][j].r = j;
        }
    }
    for(int i = 1; i <= m; i++) 
    {
        if(mx[1][i].v == 0)
            dfs(1, i);
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        if(!mx[n][i].v) cnt++;
    }
    if(cnt != 0) 
    {
        cout << "0\n" << cnt << endl;
    }else
    {
        // for(int i = 1; i <= m; i++)
        //     cout << mx[1][i].l << "-" << mx[1][i].r << endl;
        cnt = 0;
        int left = 1;
        while(left <= m)
        {
            cnt++;
            int maxTmp = 0;
            for(int i = 1; i <= m; i++)
                if(mx[1][i].l <= left) maxTmp = max(maxTmp, mx[1][i].r);
            left = maxTmp+1;
            //cout << left << endl;
        }
        cout << "1\n" << cnt << endl;
    }
    return 0;
}