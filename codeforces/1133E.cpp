#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    int l = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
            dp[i][j] = dp[i-1][j];
        while(a[i]-a[l] > 5) l++;
        for(int j = 1; j <= k; j++)
            dp[i][j] = max(dp[i][j], dp[l-1][j-1]+(i-l+1));
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
