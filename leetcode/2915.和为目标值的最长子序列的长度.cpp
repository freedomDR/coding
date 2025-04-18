/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 *
 * [2915] 和为目标值的最长子序列的长度
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> f(target+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                if (f[j-nums[i]] != 0 || j-nums[i] == 0) {
                    f[j] = max(f[j], f[j-nums[i]]+1);
                }
            }
            // for (auto v : f) 
            //     cout << v << " ";
            // cout << endl;
        }
        return f[target]==0?-1:f[target];
    }
};

// int main()  
// {
//     Solution s;
//     vector<int> arr = {1,1,5,4,5};
//     cout << s.lengthOfLongestSubsequence(arr, 3) << endl;
//     return 0;
// }
// @lc code=end

