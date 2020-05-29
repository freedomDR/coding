#include<bits/stdc++.h>

using namespace std;

int d[55][55];

void dfs(int i, int j)
{
    d[i][j] = 0;
    if(i-1>=0&&d[i-1][j]==1) dfs(i-1, j);
    if(j-1>=0&&d[i][j-1]==1) dfs(i, j-1);
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < n; j++)
                d[i][j] = s[j]-'0';
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(d[i][n-1]) dfs(i, n-1);
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(d[n-1][i]) dfs(n-1, i);
        }
        bool ok = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d[i][j]) ok = false;
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}