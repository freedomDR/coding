/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <bits/stdc++.h>

#include <memory>
using namespace std;
// 0 3
// 0 1
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // cout << l << " " << r << endl;
            if ((nums[mid] > nums[len - 1] &&
                 (target > nums[mid] || target <= nums[len - 1])) ||
                (nums[mid] < nums[len - 1] && target > nums[mid] &&
                 target <= nums[len - 1])) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        // cout << l << endl;
        return nums[min(l, len - 1)] == target ? min(l, len - 1) : -1;
    }
};

// int main()
// {
//     auto s = make_shared<Solution>();
//     auto arr = vector<int>{3, 5, 1};
//     s->search(arr, 5);
//     arr = vector<int>{4,5,6,7,0,1,2};
//     s->search(arr, 0);
// }
// @lc code=end
