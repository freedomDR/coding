/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {

    void dfs1(int pos, int fa, vector<vector<int>> & g, int t, int target, long long & ans, long long val) {
        if (t == -1) return; 
        if (pos==target&&(t==0||g[pos].size()==1)) {
            ans = val;
            return;
        }
        for (auto v:g[pos]) {
            if (v == fa) continue;
            if (ans != -1) continue;
            dfs1(v, pos, g, t-1, target, ans, val*(g[pos].size()-1));
        }
    }

    long long dfs2(int pos, int fa, vector<vector<int>> & g, int t, int target) {
        if (t==0) return pos == target;
        if (pos==target) return g[pos].size()==1;
        for (auto v:g[pos]) {
            if (v==fa) continue;
            auto res = dfs2(v, pos, g, t-1, target);
            if (res)
                return res * (g[pos].size()-1);
        }
        return 0;
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        long long ans = -1;
        vector<vector<int>> g(n+1);
        for (auto & arr:edges) {
            int x = arr[0], y = arr[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        g[1].push_back(-1);
        // dfs1(1, -1, g, t, target, ans, 1);
        // // cout << ans << endl;
        // return (ans==-1?0:1.0/ans);

        auto res = dfs2(1, -1, g, t, target);
        return (res==0?0:1.0/res);

    }
};

// int main()
// {
//     Solution s;
//     // vector<vector<int>> arr = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10},{10,11},{11,12},{12,13},{13,14},{14,15},{15,16},{16,17},{17,18},{1,19},{1,20},{1,21},{1,22},{1,23},{1,24},{1,25},{1,26},{1,27},{1,28},{1,29},{1,30},{1,31},{1,32},{1,33},{1,34},{1,35},{1,36},{2,37},{2,38},{2,39},{2,40},{2,41},{2,42},{2,43},{2,44},{2,45},{2,46},{2,47},{2,48},{2,49},{2,50},{2,51},{2,52},{2,53},{2,54},{3,55},{3,56},{3,57},{3,58},{3,59},{3,60},{3,61},{3,62},{3,63},{3,64},{3,65},{3,66},{3,67},{3,68},{3,69},{3,70},{4,71},{4,72},{4,73},{4,74},{5,75},{5,76},{6,77},{6,78},{7,79},{7,80},{8,81},{8,82},{9,83},{9,84},{10,85},{10,86},{11,87},{11,88},{12,89},{13,90},{14,91},{15,92},{16,93},{17,94}};
//     vector<vector<int>> arr = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
//     cout << s.frogPosition(7, arr, 1,7) << endl;
//     // cout << s.frogPosition(94, arr, 17, 94);
//     return 0;
// }
// @lc code=end

