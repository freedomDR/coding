#include<bits/stdc++.h>
using namespace std;
int m, n;
char g[1501][1501];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool ok;
int v[1501][1501][3];
int main()
{
    while(cin>>n>>m)
    {
        int x, y;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'S') x = i, y = j,g[i][j]='.';
            }
        }
        ok = false;
        memset(v, 0, sizeof(v));
        deque<pair<int, int>> d;
        d.push_back(make_pair(x, y));
        v[x][y][0] = 1;
        v[x][y][1] = x;
        v[x][y][2] = y;
        while(!d.empty()&&!ok)
        {
            auto it = d.front();
            d.pop_front();
            for(int i = 0; i < 4; i++)
            {
                int xx = it.first+dx[i], xp = (xx+10*n)%n;
                int yy = it.second+dy[i], yp = (yy+10*m)%m;
                if(g[xp][yp] == '#') continue;
                if(v[xp][yp][0] == 0) 
                {
                    v[xp][yp][0] = 1;v[xp][yp][1] = xx;v[xp][yp][2]=yy;d.push_back(make_pair(xx, yy));
                    /* cout << xx << " " << yy << endl; */
                    continue;
                }
                if(v[xp][yp][0]&&xx==v[xp][yp][1]&&yy==v[xp][yp][2]) continue;
                ok = true;
            }
        }
        cout << (ok?"Yes":"No") << endl;
    }
}
