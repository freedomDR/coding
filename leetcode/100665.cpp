#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> g(n);
        for (auto & arr:hierarchy) {
            int u = arr[0]-1, v = arr[1]-1;
            g[u].push_back(v);
        }
        int ans = 0;
        auto dfs = [&](this auto && self, int cur, bool parent_buy, int money) -> void {
            // cout << "cur: " << cur << " parent_buy: " << parent_buy << " money: " << money << " budge: " << budget << endl;
            // buy
            int buy_in = present[cur];
            int buy_out = future[cur];
            if (parent_buy) buy_in /= 2;
            if (buy_in <= budget) {
                money += (buy_out-buy_in);
                budget -= buy_in;
                ans = max(ans, money);
                for (auto v:g[cur]) {
                    self(v, true, money);
                }
                budget += buy_in;
                money -= (buy_out-buy_in);
            }
            // no buy
            ans = max(ans, money);
            for (auto v:g[cur]) {
                self(v, false, money);
            }
        };
        dfs(0, false, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> present = {1,2};
    vector<int> future = {4,3};
    vector<vector<int>> hierarchy = {{1,2}};
    cout << (s.maxProfit(2, present, future, hierarchy, 3)==5) << endl;
    present = {3,4};
    future = {5,8};
    cout << (s.maxProfit(2, present, future, hierarchy, 4)==4) << endl;
    present = {6,4,23};
    future = {50,48,17};
    hierarchy = {{1,3}, {1,2}};
    cout << (s.maxProfit(3, present, future, hierarchy, 28)==96) << endl;
    return 0;
}
