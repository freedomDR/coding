#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m, n, x, y, d, p;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        cin >> m >> n >> x >> y >> d >> p;
        vector<vector<int>> g(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++) 
            for(int j = 1; j <= n; j++)
                cin >> g[i][j];
        vector<vector<bool>> f(m+1, vector<bool>(n+1, false));
        vector<pair<int, int>> q;
        q.push_back(make_pair(x, y));
        f[x][y] = true;
        vector<int> t;
        while(d--)
        {
            vector<pair<int, int>> qq;
            for(auto &it:q)
            {
                int xx = it.first, yy = it.second;
                for(int i = 0; i < 4; i++)
                {
                    int nx = xx+dx[i], ny = yy+dy[i];
                    if(nx == 0 || nx > m || ny == 0 || ny > n || f[nx][ny] || g[nx][ny] == -1) continue;
                    if(g[nx][ny] > 0) t.push_back(g[nx][ny]);
                    f[nx][ny] = true;
                    qq.push_back(make_pair(nx, ny));
                }
            }
            q = qq;
        }
        sort(t.begin(), t.end());
        auto last = unique(t.begin(), t.end());
        t.erase(last, t.end());
        if(t.size() == 0) cout << -1 << endl;
        else
        {
            if(p == 1) {cout << 0 << endl;continue;}
            //cout << t.size() << endl;
            int ans = 1e8;
            for(int i = p-1; i < t.size(); i++)
                ans = min(ans, t[i]-t[i-p+1]);
            if(ans != 1e8) cout << ans << endl;
            else cout << "no" << endl;
        }
    }    
    return 0;
}