/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <memory>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len;
        while (l < r) {
            // cout << l << " " << r << " " << len << endl;
            int mid = l + (r-l)/2;
            if (mid != len-1 && nums[mid] == nums[len-1]) {
                len--;
                r = min(r, len);
                continue;
            }
            if (nums[mid] > nums[len-1]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        // cout << l << endl;
        return nums[min(l, (int)nums.size()-1)];
    }
};

// int main()
// {
//     auto s = make_shared<Solution>();
//     auto arr = vector<int>{4,1,3};
//     cout << s->findMin(arr) << endl;
//     arr = vector<int>{3,1,3};
//     cout << s->findMin(arr) << endl;
//     arr = vector<int>{10,1,10,10,10};
//     cout << s->findMin(arr) << endl;
//     return 0; 
// }
// @lc code=end

