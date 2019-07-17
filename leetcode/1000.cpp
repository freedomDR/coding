#include <bits/stdc++.h>

using namespace std;

int mergeStones(vector<int> stones, int K)
{
    const int n = stones.size();
    if((n-1)%(K-1)) return -1;
    vector<int> sums(n+1, 0);
    for(int i = 1; i <= n; i++) sums[i] = sums[i-1]+stones[i-1];
    vector<vector<vector<int>>> dp(n , vector<vector<int>>(n, vector<int>(K+1, 1e9)));
    for(int i = 0; i < n; i++) dp[i][i][1] = 0;
    for(int l = 2; l <= n; l++) //length
        for(int i = 0; i <= n-l; i++)
        {
            int j = i+l-1;
            for(int k = 2; k <= min(K, l); k++)
            {
                for(int m = i; m < j; m += K-1)
                    dp[i][j][k] = min(dp[i][j][k], dp[i][m][1]+dp[m+1][j][k-1]);
                cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
            dp[i][j][1] = dp[i][j][K] + sums[j+1] - sums[i];
        }
    return dp[0][n-1][1];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int K, n;
    cin>>K>>n;
    vector<int> stones(n);
    for(int i = 0; i < n; i++) cin>>stones[i];
    int ans = mergeStones(stones, K);
    cout<<ans<<endl;
    return 0;
}
