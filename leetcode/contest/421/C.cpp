#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[2][201][201];
const long long MOD = 1e9+7;

long long gcd(long long a, long long b) {
    return b==0?a:gcd(b, a%b);
}

int subsequencePairCount(vector<int>& nums) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int max_v = *std::max_element(nums.begin(), nums.end());

    auto update = [](long long & a, long long & b) {
        a = (a+b)%MOD;
    };
    for(int i = 1; i <= nums.size(); i++) {
        int x = nums[i-1];
        for (int j = 0; j <= max_v; j++)
            for (int k = 0; k <= max_v; k++)
                dp[i%2][j][k] = 0;
        for (int j = 0; j <= max_v; j++) {
            for (int k = 0; k <= max_v; k++) {
                update(dp[i%2][gcd(x, j)][k], dp[(i+1)%2][j][k]);
                update(dp[i%2][j][gcd(x, k)], dp[(i+1)%2][j][k]);
                update(dp[i%2][j][k], dp[(i+1)%2][j][k]);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= max_v; i++) {
        update(ans, dp[nums.size()%2][i][i]);
    }
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    // cout << subsequencePairCount(arr) << "\n";
    arr = {10, 20, 30, 40};
    cout << subsequencePairCount(arr) << "\n";
    arr = {1, 1, 1, 1};
    cout << subsequencePairCount(arr) << "\n";
    return 0; 
}