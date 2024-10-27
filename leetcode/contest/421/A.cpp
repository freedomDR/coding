#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) { return a % b == 0 ? b : gcd(b, a % b); }

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long maxScore(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0] * nums[0];

    long long ans = 0;
    for (int i = -1; i < (int) nums.size(); i++) {
        long long gcdv = -1;
        long long lcmv = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) continue;
            if (gcdv == -1) {
                gcdv = nums[j];
                lcmv = nums[j];
                continue;
            }
            gcdv = gcd(gcdv, nums[j]);
            lcmv = lcm(lcmv, nums[j]);
        }

        ans = max(ans, gcdv * lcmv);
    }
    return ans;
}

int main() { 
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << maxScore(arr) << endl;
    vector<int> arr1 = {2, 4, 8, 16};
    cout << maxScore(arr1) << endl;
    return 0; 
}