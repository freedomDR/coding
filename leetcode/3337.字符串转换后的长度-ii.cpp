/*
 * @lc app=leetcode.cn id=3337 lang=cpp
 *
 * [3337] 字符串转换后的长度 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <array>
#include <numeric>
#include <unordered_map>
using namespace std;

constexpr int MOD = 1e9+7;
constexpr int SZ = 26;
using Matrix = array<array<int, SZ>, SZ>;

Matrix mul(const Matrix & a, const Matrix & b) {
    Matrix c = {};
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                c[i][j] = (c[i][j] + (long long) a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return c;
}

Matrix pow(Matrix & a, int b) {
    Matrix res = {};
    for (int i = 0; i < SZ; i++) 
        res[i][i] = 1;
    while(b) {
        if (b%2) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> cnt(SZ, 0);
        for (char c:s)
            cnt[c-'a']++;
        Matrix m = {};
        for (int i = 0; i < SZ; i++) {
            for (int j = i+1; j <= nums[i]+i; j++) {
                m[i][j%SZ] = 1;
            }
        }
        Matrix res = pow(m, t);
        long long ans = 0;
        for (int i = 0; i < SZ; i++) {
            ans += reduce(res[i].begin(), res[i].end(), 0LL)*cnt[i];
        }
        return ans%MOD;
    }
};
// @lc code=end

