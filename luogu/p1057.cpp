#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[1][0] = 1;
    for(int k = 1; k <= m; k++) {
        dp[1][k] =  dp[2][k-1] + dp[n][k-1];
        for(int i = 2; i <= n-1; i++)
            dp[i][k] = dp[i-1][k-1] + dp[i+1][k-1];
        dp[n][k] = dp[n-1][k-1] + dp[1][k-1];
    }
    cout << dp[1][m] << endl;
    return 0;
}
