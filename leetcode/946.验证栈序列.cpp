/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cmath>
#include <deque>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> d;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) {
            d.push(pushed[i]);
            while(!d.empty()&&d.top()==popped[j]) {
                j++;
                d.pop();
            }
        }
        return d.empty();
    }
};
// @lc code=end

