/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool check(string &num, int i, int j) {
        // cout << i << " " << j << endl;
        string a_str = num.substr(0, i+1);
        string b_str = num.substr(i+1, j-i);
        int pos = j+1;
        while (pos < num.size()) {
            string c_str = to_string(stoll(a_str) + stoll(b_str));
            if (num.substr(pos, c_str.size()) != c_str) {
                return false;
            }
            pos += c_str.size();
            a_str = b_str;
            b_str = c_str;
        }
        return true;
    }

public:
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size(); i++) {
            for (int j = i+1; j < num.size()-1 && (num.size()-j) >= max(i, j-i+1); j++) {
                if (check(num, i, j)) {
                    return true;
                }
                if (num[i+1] == '0') break;
            }
            if (num[0] == '0') break;
        }
        return false;
        
    }
};

// int main()
// {
//     Solution s;
//     cout << s.isAdditiveNumber("999999999999999999999999") << endl;
//     return 0;
// }
// @lc code=end

