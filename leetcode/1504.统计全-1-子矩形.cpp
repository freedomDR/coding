/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 *
 * [1504] 统计全 1 子矩形
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // solution 1
        // int ans = 0;
        // int m = mat.size(), n = mat[0].size();
        // for (int top = 0; top < m; top++) {
        //     vector<int> arr(n);
        //     for (int bottom = top; bottom < m; bottom++) {
        //         int h = bottom-top+1;
        //         int last = -1;
        //         for (int i = 0; i < n; i++) {
        //             arr[i] += mat[bottom][i];
        //             if (arr[i]!=h)
        //                 last = i;
        //             else
        //                 ans += i-last;
        //         }
        //     }
        // }
        // return ans;

        // solution 2
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> hh(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) hh[j]++;
                else hh[j] = 0;
            }

            stack<vector<int>> st;
            st.push({-1, 0, -1});
            for (int j = 0; j < n; j++) {
                while (st.top()[2] >= hh[j])
                    st.pop();
                auto pos = st.top()[0];
                auto f = st.top()[1];
                f += (j-pos)*hh[j];
                ans += f;
                st.push({j, f, hh[j]});
            }
        }
        return ans;
        
    }
};
// @lc code=end

