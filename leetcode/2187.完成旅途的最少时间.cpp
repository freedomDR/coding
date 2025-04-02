/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long r = *(ranges::max_element(time)) * 1L * totalTrips;
        long long l = 1;
        while (l < r) {
            long long mid = l + (r-l)/2;
            long long sum_trips = 0;
            for (auto & v : time) {
                sum_trips += mid/v;
                if (sum_trips >= totalTrips)
                    break;
            }
            //cout << mid << " " << sum_trips << endl;
            if (sum_trips < totalTrips) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

