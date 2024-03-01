#include <bits/stdc++.h>

using namespace std;

bool slove(vector<int>  nums)
{
    auto sz = nums.size();
    if(sz <= 1) return false;
    if(sz == 2) return nums[0] == nums[1];
    auto time_1 = std::chrono::high_resolution_clock::now();
    bool dp1 = false, dp2 = false, dp3 = false;
    dp2 = nums[0]==nums[1];
    dp3 = (nums[0]+nums[1]==nums[2]*2)||(nums[0]+1==nums[1]&&nums[1]+1==nums[2]);
    for(int i = 3; i < sz; i++)
    {
        bool dp4 = dp2&&(nums[i]==nums[i-1]);
        dp4 |= dp1&&((nums[i]+nums[i-1]==nums[i-2]*2)||(nums[i-2]+1==nums[i-1]&&nums[i-1]+1==nums[i]));
        dp1 = dp2;
        dp2 = dp3;
        dp3 = dp4;
    }
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cost = time_2-time_1;
    std::cout << "cost " << cost.count() << "ms\n";
    return dp3;
}

int main()
{
    std::cout << slove({1,1,1}) << "\n";
    std::cout << slove({1,1}) << "\n";
    std::cout << slove({1}) << "\n";
    std::cout << slove({1, 2, 3}) << "\n";
    std::cout << slove({1, 1, 2, 2, 2}) << "\n";
    std::cout << slove({1, 1, 2, 3, 4}) << "\n";
    return 0;
}