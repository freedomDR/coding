/*
 * @lc app=leetcode.cn id=3362 lang=cpp
 *
 * [3362] 零数组变换 III
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        ranges::sort(queries, {}, [](auto & q) {return q[0];});
        priority_queue<int> pq;
        int n = nums.size();
        vector<int> diff(n+1);
        int tmp = 0, j = 0;
        for (int i = 0; i < n; i++) {
            tmp += diff[i];
            while(j<queries.size()&&queries[j][0]<=i) {
                pq.push(queries[j++][1]);
            }
            while(tmp<nums[i]&&!pq.empty()&&pq.top()>=i) {
                tmp++;
                diff[pq.top()+1]--;
                pq.pop();
            }
            if (tmp<nums[i]) return -1;
        }
        return pq.size();
    }
};
// @lc code=end

