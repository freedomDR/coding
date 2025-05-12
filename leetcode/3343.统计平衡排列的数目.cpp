/*
 * @lc app=leetcode.cn id=3343 lang=cpp
 *
 * [3343] 统计平衡排列的数目
 */

// @lc code=start
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9+7;
constexpr int MAX_N = 80;
ll F[MAX_N+1];
ll INV_F[MAX_N+1];
ll pow(ll x, int n) {
    ll res = 1;
    while (n) {
        if (n%2) {
            res  = res*x%MOD;
        }
        x = x*x%MOD;
        n = n>>1;
    }
    return res;
}

auto init = []{
    F[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        F[i] = F[i-1]*i%MOD;
    }
    INV_F[MAX_N] = pow(F[MAX_N], MOD-2);
    for (int i = MAX_N; i > 0; i--) {
        INV_F[i-1] = INV_F[i]*i%MOD; 
    }
    return 0;
}();

class Solution {
public:
    int countBalancedPermutations(string num) {
        int tot = 0;
        vector<int> cnt(10, 0);
        for (char c:num) {
            cnt[c-'0']++;
            tot += (c-'0');
        }
        if (tot%2) return 0;
        int n = num.size();
        int odd_number = (n+1)/2, even_number = n/2;
        vector<vector<vector<ll>>> cache(10, vector<vector<ll>>(odd_number+1, vector<ll>(tot/2+1, -1)));
        auto dfs = [&](this auto && self, int i, int odd_cnt, int odd_sums) -> ll {
            // cout << i << " " << odd_cnt << " " << odd_sums << endl;
            if (i == -1) {
                return odd_sums==0&&odd_cnt==0;
            }
            ll & res = cache[i][odd_cnt][odd_sums];
            if (res != -1) return res;
            res = 0;
            for (int k = 0; k <= cnt[i]; k++) {
                if (odd_cnt-k<0) break;
                if (odd_sums-i*k<0) break;
                ll tmp = (INV_F[k]*INV_F[cnt[i]-k]%MOD)*self(i-1, odd_cnt-k, odd_sums-i*k)%MOD;
                // cout << "tmp: " << tmp << endl;
                res = (res+tmp)%MOD; 
            }
            return res;
        };
        return F[odd_number]*F[even_number]%MOD*dfs(9, odd_number, tot/2)%MOD;
    }
};

// int main()
// {
    // Solution s;
    // cout << s.countBalancedPermutations("123") << endl;
    // cout << s.countBalancedPermutations("112") << endl;
    // cout << s.countBalancedPermutations("886666") << endl;
    // cout << s.countBalancedPermutations("579425002063451982937835161035012178922831665347") << endl;
    // cout << s.countBalancedPermutations("56977596171300986444383510620056531554861778447054") << endl;
    // cout << s.countBalancedPermutations("00000000000000000000000000000000000000000000000000000000000000000000000000000000") << endl;
//     return 0;
// }
// @lc code=end

