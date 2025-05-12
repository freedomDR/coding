#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        ll ans = 0;
        vector<int> ring, chain;
        vector<vector<int>> g(n, vector<int>());
        vector<bool> vis(n, false);
        vector<int> deg(n);
        for (auto & arr:edges) {
            int x = arr[0], y = arr[1];
            g[x].push_back(y);
            g[y].push_back(x);
            deg[x]++;
            deg[y]++;
        } 

        auto dfs = [&](this auto && self, int v, int len) -> void {
            vis[v] = true;
            int cnt = 0;
            for (auto to:g[v]) {
                if (vis[to]) continue;
                self(to, len+1);
                cnt++;
            }
            if (cnt == 0) {
                if (g[v].size()==1) chain.push_back(len);
                if (g[v].size()==2) ring.push_back(len);
            }
        };
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (deg[i]==1)
                dfs(i, 1);
        }
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            dfs(i, 1);
        }
        ranges::sort(ring);
        ranges::sort(chain);
        // cout << "ring: ";
        // for (auto v:ring) {
        //     cout << v << " ";
        // }
        // cout << endl;
        // cout << "chain: ";
        // for (auto v:chain) {
        //     cout << v << " ";
        // }
        // cout << endl;
        ll k = n;
        for (auto it = ring.rbegin(); it != ring.rend(); it++) {
            for (int i = 1; i < *it; i++) {
                if (i==1) {
                    ans += (k-i)*(k-i+1);
                } else if (i!=*it-1) {
                    ans += (k-i)*(k-i+2);
                } else {
                    ans += (k-i)*(k-i+1)+(k-i)*(k-i+2);
                }
            }
            k -= *it;
        }
        for (auto it = chain.rbegin(); it != chain.rend(); it++) {
            for (int i = 1; i < *it; i++) {
                if (i==1) {
                    ans += (k-i)*(k-i+1);
                } else {
                    ans += (k-i)*(k-i+2);
                }             
            }
            k -= *it;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6}};
    cout << s.maxScore(7, arr) << endl;
    arr = {{0,3},{4,5},{2,0},{1,3},{2,4},{1,5}};
    cout << s.maxScore(6, arr) << endl;
    arr = {{4,0},{2,0},{1,2},{1,3}};
    cout << s.maxScore(5, arr) << endl;
    return 0;
}