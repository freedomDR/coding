#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& g, int i, int j, int n)
{
    if(i < 0 || j < 0 || i == n+2 || j == n+2 || g[i][j] == -1 || g[i][j] == 1) return;
    g[i][j] = -1;
    dfs(g, i+1, j, n);
    dfs(g, i-1, j, n);
    dfs(g, i, j+1, n);
    dfs(g, i, j-1, n);
}
int main()
{
    int n; cin >> n;
    vector<vector<int>> g(n+2, vector<int>(n+2, 0));
    for(int i = 1; i < n+1; ++i) 
    {
        for(int j = 1; j < n+1; ++j)
        {
            cin>>g[i][j];
        }
    }
    dfs(g, 0, 0, n);
    for(int i = 1; i < n+1; ++i) 
    {
        for(int j = 1; j < n+1; ++j)
        {
            if(g[i][j] == -1) {cout<<"0 ";continue;}
            if(g[i][j] == 1) {cout<<"1 ";continue;}
            if(g[i][j] == 0) {cout<<"2 ";continue;}
        }
        cout<<endl;
    }

    return 0;
}
