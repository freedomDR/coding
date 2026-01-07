#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n);
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
         }
        sort(nums.begin(), nums.end(), [](int x, int y) {
            int sums1 = 0;
            int ori_x = x, ori_y = y;
            while(x) {
                sums1 += x%10;
                x /= 10;
            }
            int sums2 = 0;
            while(y) {
                sums2 += y%10;
                y /= 10;
            }
            //cout << "x: " << x << " sums1: " << sums1 << " y: " << y << " sums2: " << sums2 << endl;
            if (sums1 < sums2) return true;
            if (sums1 > sums2) return false;
            return ori_x <= ori_y;
        });
        // for (int x:nums)
        //     cout << x << " ";
        // cout << endl;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) ans++;
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
            }
        }
        return n-ans;
        
    }
};

int main()
{
    Solution s;
    vector<int> arr = {875031872,661889073,850559628};
    //{41, 48, 48}
    cout << s.minSwaps(arr) << endl;
    return 0;
}