#include <bits/stdc++.h>
#include <algorithm>


int main()
{
    int n, k; std::cin >> n >> k;
    k = n-k;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(k+1));
    for(int i = 0; i < n; i++) dp[i][1] = 1;
    long long sums = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i]%a[j] != 0) continue;
            for(int ii = 2; ii <= k; ii++)
            {
                dp[i][ii] += dp[j][ii-1];
                dp[i][ii] %= (long long)(1e9+7);
            }
        }
        sums = (sums+dp[i][k])%(long long)(1e9+7);
    }
    std::cout << sums << std::endl;
    return 0;
}
