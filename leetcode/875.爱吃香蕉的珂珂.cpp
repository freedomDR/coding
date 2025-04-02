/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *(ranges::max_element(piles))+1;
        int l = 1;
        while (l < r) {
            int mid = l + (r-l)/2;
            int need = 0;
            for (auto & v : piles) {
                need += (v-1)/mid + 1;
                if (need > h) 
                    break;
            }
            if (need > h) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

