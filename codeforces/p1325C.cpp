#include<bits/stdc++.h>

using namespace std;

struct Edge
{
    int next;
    int to;
}e[222222];
int head[111111], cnt;

void addEdge(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> in(n+1);
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> ans(n);
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        in[u]++;
        in[v]++;
        addEdge(u, v);
        addEdge(v, u);
        ans[i].first = u;
        ans[i].second = v;
    }
    // cout << "test" << endl;
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        // cout << in[i] << endl;
        if(in[i]==1) 
        {
            q.push(i);
        }
    }
    int st = 1;
    vector<bool> vis(n, false);
    // cout << "*******" << endl;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        vis[top] = true;
        int tmp = -1;
        for(int i=head[top];i;i=e[i].next)
        {
            int v = e[i].to;
            if(vis[v]==false)
            {
                tmp = v;
            }
        }
        if(tmp == -1) break;
        in[tmp]--;
        if(in[tmp]==1)q.push(tmp);
        if(top>tmp) swap(top, tmp);
        if(st == n-1) st = 0;
        mp[make_pair(top, tmp)] = st++;
    }
    for(int i = 0; i < n-1; i++)
    {
        cout << mp[ans[i]] << endl;
    }
    return 0;
}