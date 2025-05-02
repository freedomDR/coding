/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();

        vector<int> arr(m+1);
        arr[m] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]=='1') arr[j] = ++arr[j];
                else arr[j] = 0; 
            }
            // for (int ii = 0; ii < arr.size(); ii++) cout << arr[ii] << " ";
            // cout << endl;

            stack<int> st;
            st.push(-1);
            for (int ii = 0; ii < arr.size(); ii++) {
                while(st.size()>1&&arr[ii]<=arr[st.top()]) {
                    auto p = st.top();
                    st.pop();
                    ans = max(ans, arr[p]*(ii-st.top()-1));
                }
                st.push(ii);
            }
        }
        return ans;
    }
};

// int main()
// {
//     vector<vector<char>> a = {{'1','0','1','1','1'},{'0','1','0','1','0'},{'1','1','0','1','1'},{'1','1','0','1','1'},{'0','1','1','1','1'}};
//     Solution s;
//     cout << s.maximalRectangle(a) << endl;
//     return 0;
// }
// @lc code=end

