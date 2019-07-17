#include <bits/stdc++.h>

using namespace std;

int dp[100][100], n, mid, len, ans;

void dfs(int rpos, int lpos, int sum){
    if(rpos == n){
        ans = max(sum, ans);
        return;
    }
    dfs(rpos+1, lpos, sum+dp[rpos+1][lpos]);
    dfs(rpos+1, lpos+1, sum+dp[rpos+1][lpos+1]);
}

int main()
{
    while(scanf("%d", &n) != EOF){
        memset(dp, 0, sizeof(int)*10000);
        for(int i = 1; i <= n; i++){
            len = 1;
            for(int j = 1; j <= i; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        ans = 0;
        dfs(1,1,dp[1][1]);
        printf("%d\n", ans);
    }
    return 0;
}
