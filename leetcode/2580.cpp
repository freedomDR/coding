#include <bits/stdc++.h>

int slove(std::vector<std::vector<int>> & ranges)
{
    int ans = 1;
    std::ranges::sort(ranges, [](auto & v1, auto & v2) {return v1[0] < v2[0];});
    int max_r = -1;
    for(int i = 0; i < ranges.size(); i++)
    {
        if(max_r < ranges[i][0])
        {
            ans *= 2;
            ans %= int(1e9+7);
        }
        max_r = std::max(max_r, ranges[i][1]);
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int>> arr = {{6, 10}, {5, 15}};
    std::cout << slove(arr) << std::endl;
    return 0;
}