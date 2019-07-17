#include<bits/stdc++.h>
using namespace std;

int sloveDP(vector<int>& nums)
{
    int maxV = nums[0], temp = 0;
    for(int i = 0; i < int(nums.size()); i++){
        temp = max(nums[i], temp+nums[i]);
        maxV = max(temp, maxV);
    }
    return maxV;
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << sloveDP(nums) << endl;
    return 0;
}
