#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    //row
    for(int i = 0; i < n; i++) {
        int l = 0;
        while(l < n && s[i][l] == 'W') l++;
        if(l == n) {dp[0][0]++;continue;}
        int r = n-1;
        while(~r && s[i][r] == 'W') r--;
        if(r-l+1 > k) continue;
        int r1 = i+1, l1 = l+1;
        int r2 = max(0, i-k+1), l2 = max(r-k+1, 0);
        dp[r2][l2]++;dp[r2][l1]--;
        dp[r1][l1]++;dp[r1][l2]--;
    }
    //column
    for(int i = 0; i < n; i++) {
        int l = 0;
        while(l < n && s[l][i] == 'W') l++;
        if(l == n) {dp[0][0]++;continue;}
        int r = n-1;
        while(~r && s[r][i] == 'W') r--;
        if(r-l+1 > k) continue;
        int l1 = i+1, r1 = l+1;
        int l2 = max(0, i-k+1), r2 = max(r-k+1, 0);
        dp[r2][l2]++;dp[r2][l1]--;
        dp[r1][l1]++;dp[r1][l2]--;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j+1] += dp[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i+1][j] += dp[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
