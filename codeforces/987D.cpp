#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m, s, k;
    cin>>n>>m>>k>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<int>> dist(k, vector<int>(n, -1));
    for(int type = 0; type < k; type++){
        vector<int> que;
        for(int i = 0; i < n; i++){
            if(a[i] == type){
                dist[type][i] = 0;
                que.push_back(i);
            }
        }
        for(int b = 0; b < (int)que.size(); b++){
            for(int u: g[que[b]]){
                if(dist[type][u] == -1){
                    dist[type][u] = dist[type][que[b]] + 1;
                    que.push_back(u);
                }
            }
        }
    }  
    vector<int> d(k);
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < k; j++){
            d[j] = dist[j][i];
        }
        sort(d.begin(), d.end());
        long long sum = 0;
        for(int j = 0; j < s; j++)
            sum += d[j];
        cout<<sum<<" ";
    }
    cout<<"\n";
    return 0;
}
