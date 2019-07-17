#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>b[i][j];
    bool ok = true;
    for(int s = 0; s < n&&ok; s++)
    {
        map<int, int> t;
        for(int i = s, j = 0; i >= 0 && j < m && ok; i--,j++)
        {
            t[a[i][j]]++;
            t[b[i][j]]--;
        }
        for(auto item:t)
        {
            if(item.second != 0)
            {
                ok = false;
                break;
            }
        }
    }
    for(int s = 0; s < m&&ok; s++)
    {
        map<int, int> t;
        for(int i = n-1, j = m-1-s; i >= 0 && j < m && ok; i--,j++)
        {
            t[a[i][j]]++;
            t[b[i][j]]--;
        }
        for(auto item:t)
        {
            if(item.second != 0)
            {
                ok = false;
                break;
            }
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
    return 0;
}
