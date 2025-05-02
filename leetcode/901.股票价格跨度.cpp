/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;
    int cnt = -1;
public:
    StockSpanner() {
        st.emplace(-1, INT_MAX);
    }
    
    int next(int price) {
        while (price >= st.top().second) 
            st.pop();
        int ans = ++cnt-st.top().first;
        st.emplace(cnt, price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

