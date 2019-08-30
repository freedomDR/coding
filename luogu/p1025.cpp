#include<bits/stdc++.h>
using namespace std;

void dfs(int last, int sum, int cur, int n, int k, int& ans) {
    if(cur == k) {
        if(sum == n) ans++;
        return;
    }
    for(int i = last; sum+(k-cur)*i <= n; i++) {
        dfs(i, sum+i, cur+1, n, k, ans);
    }

}

void dfs_slove() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    dfs(1, 0, 0, n, k, ans);
    cout << ans << endl;
}

void dp_slove() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    for(int i = 1; i <= n; i++) dp[i][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= k; j++) {
            if(i > j) dp[i][j] = dp[i-1][j-1]+dp[i-j][j];
            else dp[i][j] = dp[i-1][j-1];
        }
    }
    cout << dp[n][k] << endl;
}

int main(){
    dfs_slove();
    /* dp_slove(); */
    return 0;
}
