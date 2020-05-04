#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n+1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<vector<int>> e(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        bool ok = true;
        for(int j = 0; j < e[i].size(); j++)
        {
            if(h[e[i][j]]>=h[i]) {ok = false;break;}
        }
        if(ok) cnt++;
    }
    cout << cnt << endl;
    return 0;
}