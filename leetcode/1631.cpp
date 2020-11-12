#include<iostream>
#include<vector>
#include<cstdio>
#include<stack>
#include<tuple>
#include<algorithm>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
bool check(int x, int y, vector<bool>& vis, int n, int m, vector<vector<int>>& arr, int t)
{
    if(x == n-1 && y == m-1) return true;
    vis[x*m+y] = true;
    bool ret = false;
    for(int i = 0; i < 4; i++)
    {
        int tx = x+dx[i], ty = y+dy[i];
        if(tx >= 0 && ty >= 0 && tx < n && ty < m && !vis[tx*m+ty] && abs(arr[x][y]-arr[tx][ty]) <= t)
        {
            ret |= check(tx, ty, vis, n, m, arr, t);
            if(ret) return ret;
        }
    }
    return ret;
}
int slove1(vector<vector<int>> &arr)
{
    int ans = 0;
    int n = arr.size(), m = arr[0].size();
    int l = 0, r = 1e6;
    vector<bool> vis(n*m, false);
    while(l < r)
    {
        int mid = l + (r-l)/2;
        fill(vis.begin(), vis.end(), false);
        vis[0] = true; 
        if(check(0, 0, vis, n, m, arr, mid)) r=mid;
        else l=mid+1;
    }
    return l;
}

int slove2(vector<vector<int>> &arr)
{
    int ans = 0;
    int n = arr.size(), m = arr[0].size();
    int l = 0, r = 1e6;
    vector<bool> vis(n*m);
    while(l < r)
    {
        int mid = l+(r-l)/2;
        bool check = false;
        fill(vis.begin(), vis.end(), false);
        stack<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty())
        {
            auto [x, y] = q.top();
            q.pop();
            vis[x*m+y] = true; 
            if(x == n-1 && y == m-1)
            {
                check = true;
                break;
            }
            for(int i = 0; i < 4; i++)
            {
                int tx = x+dx[i], ty = y+dy[i];
                if(tx >= 0 && ty >= 0 && tx < n && ty <m && !vis[tx*m+ty] && abs(arr[x][y]-arr[tx][ty]) <= mid)
                {
                    q.push({tx, ty});
                }
            }
        }
        if(check) r = mid;
        else l = mid+1;
    }
    return l;
}

int slove3(vector<vector<int>> &arr)
{
    vector<tuple<int, int, int>> edge;
    int n = arr.size(), m = arr[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i>0)
                edge.push_back({abs(arr[i][j]-arr[i-1][j]), i*m+j, i*m+j-m});
            if(j>0)
                edge.push_back({abs(arr[i][j]-arr[i][j-1]), i*m+j, i*m+j-1});
        }
    }
    sort(edge.begin(), edge.end(), [](auto &p1, auto &p2) {return p1 < p2;});
    vector<int> f(n*m);
    for(int i = 0; i < n*m; i++)
        f[i] = i;
    function<int(int)> look = [&](int x) 
    {
        if(f[x] == x) return x;
        else return f[x] = look(f[x]);
    };
    for(int i = 0; i < edge.size(); i++)
    {
        auto [val, u, v] = edge[i];
        f[look(u)] = look(v);
        if(look(0) == look(n*m-1)) return val;
    }
    return 0;
}

int slove4(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    vector<bool> vis(n*m, false);
    vector<int> dis(n*m, 0);
    return 0;
}
int main()
{
    #ifdef LOCAL 
        freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    int ans = slove4(arr);
    cout << ans << endl;
    return 0;
}