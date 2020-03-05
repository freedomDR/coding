#include<bits/stdc++.h>

using namespace std;
int n, x[1100][1100], y[1100][1100];
char g[1100][1100];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1, 1};
char c[4] = {'U', 'D', 'R', 'L'};

void dfs(int i, int j)
{
    for(int p = 0; p < 4; p++)
    {
        int ii = i+dx[p], jj = j+dy[p];
        if(ii>=0&&ii<n&&jj>=0&&jj<n&&g[ii][jj]=='\0'&&x[ii][jj]==-2&&y[ii][jj]==-2)
        {
            g[ii][jj] =  c[p];      
            dfs(ii, jj);
        }
    }
}

void dfs1(int in, int jn, int i, int j)
{
    for(int p = 0; p < 4; p++)
    {
        int ii = i+dx[p], jj = j+dy[p];
        if(ii>=0&&ii<n&&jj>=0&&jj<n&&g[ii][jj]=='\0'&&x[ii][jj]==in&&y[ii][jj]==jn)
        {
            g[ii][jj] = c[p];      
            dfs1(in, jn, ii, jj);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;y[i][j]--;
            if(x[i][j] == i && y[i][j] == j) 
            {
                g[i][j] = 'X';
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(x[i][j] == -2 && y[i][j] == -2 && g[i][j] == '\0')
            {
                dfs(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] == 'X')
            {
                dfs1(i, j, i, j);
            }
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(g[i][j] == '\0')
            {
                ok = false;
            }
        }
    }
    if(!ok)
    {
        cout << "INVALID" << endl;
        return 0;
    }
    cout << "VALID" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << g[i][j];
        cout << endl;
    }
    return 0;
}