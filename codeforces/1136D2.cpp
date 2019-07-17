#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<int> p(n);
    set<pair<int, int>> adj;
    for(int i = 0; i < n; i++) cin>>p[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;cin>>u>>v;
        adj.insert(make_pair(u, v));
    }
    int st = 0, ind = n-1, me = p[ind];
    function<void(int)> slove = [&st, &p, &adj, &slove](int ind)
    {
        while(true)
        {
            while(st < ind && adj.find(make_pair(p[ind-1], p[ind])) != adj.end())
            {
                swap(p[ind-1], p[ind]);
                ind--;
            }
            if(st == ind){st++;return;}
            slove(ind-1);
        }
    };
    slove(ind);
    for(int i = 0; i < n; i++)
    {
        if(p[i] == me)
        {
            cout<<(n-i-1)<<endl;
        }
    }
    return 0;
}
