#include <bits/stdc++.h>

using namespace std;

void dfs(int r, int c, auto& plant, int n, auto& visit, auto& v)
{
    /* cout<<"dfs: "<<r<<" "<<c<<endl; */
    if(r<0||c<0||r>=n||c>=n||plant[r][c]=='1'||visit[r][c]) return;
    visit[r][c] = 1;
    v.push_back(make_pair(r, c));
    dfs(r,c-1,plant, n, visit, v);
    dfs(r,c+1,plant, n, visit, v);
    dfs(r-1,c,plant, n, visit, v);
    dfs(r+1,c,plant, n, visit, v);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,r1,r2,c1,c2;
    cin>>n>>r1>>c1>>r2>>c2;r1--;r2--;c1--;c2--;
    vector<string> plant(n);
    vector<vector<int>> visit(n, vector<int>(n, 0));
    vector<pair<int, int>> v1,v2;
    for(int i = 0; i < n; i++) cin>>plant[i];
    dfs(r1, c1, plant, n, visit, v1);
    if(visit[r2][c2]) 
    {
        cout<<"0"<<endl;
        return 0;
    }
    dfs(r2, c2, plant, n, visit, v2);
    int ans = 25000;
    for(auto i:v1)
    {
        for(auto j:v2)
        {
            ans = min(ans, abs(i.first-j.first)*abs(i.first-j.first)+abs(i.second-j.second)*abs(i.second-j.second));
        }
    }
    cout<<ans<<endl;
    return 0;
}
