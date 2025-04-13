/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {

    bool check(string & ip) {
        if (ip.size() == 1) return true;
        if (ip[0] == '0') return false;
        if (stoll(ip) > 255) return false;
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> ips;
        auto dfs = [&](this auto && self, int pre_pos) {
            if (ips.size() == 3) {
                // last
                if (pre_pos == s.size()) return;
                auto last = s.substr(pre_pos);
                if (check(last)) {
                    ans.push_back(ips[0] + "." + ips[1] + "." + ips[2] + "." + last);
                }
                return;
            }
            for (int i = pre_pos; i < s.size() && pre_pos-i+1<4; i++) {
                auto ip = s.substr(pre_pos, i - pre_pos + 1);
                if (check(ip)) {
                    ips.push_back(ip);
                    self(i + 1);
                    ips.pop_back();
                } else {
                    break;
                }
            }
        };
        dfs(0);
        return ans;
    }
};

// int main()
// {
//     Solution s;
//     cout << s.restoreIpAddresses("0279245587303").size() << endl;
//     return 0;
// }
// @lc code=end

