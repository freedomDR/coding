#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    int g[n+1][n+1], v[n+1][n+1], ans[n+1][n+1];
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    memset(g, 0, sizeof g);
    memset(ans, 0, sizeof ans);
    memset(v, 0, sizeof v);
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++) {
            g[i][j+1] = int(s[j]-'0');
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(v[i][j] != 0) continue;
            int sums = 0;
            for(int k = 0; k < 2; k++) {
                queue<pair<int, int>> q;
                q.push({i, j});
                v[i][j]++;
                while(!q.empty()){
                    auto pos = q.front();
                    q.pop();
                    if(k == 0)sums++;
                    else ans[pos.first][pos.second] = sums;
                    /* cout << pos.first << " " << pos.second  << " " << ans[pos.first][pos.second] << endl; */
                    for(int z = 0; z < 4; z++) {
                        int x = pos.first+d[z][0], y = pos.second+d[z][1];
                        if(x == 0 || x == n+1 || y == 0 || y == n+1 || g[pos.first][pos.second] == g[x][y] || ((k==0&&v[x][y])||(k==1&&v[x][y]==2)))  continue;
                        q.push({x, y});
                        v[x][y]++;
                    }
                }
            }
            /* cout << sums << endl; */
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        cout << ans[x][y] << endl;
    }
    
    return 0;
}
