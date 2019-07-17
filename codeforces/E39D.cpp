#include <bits/stdc++.h>

using namespace std;

int dp[510], mn[510], sum[510], sdp[510];
char s[510];
int n, m, k;

int main()
{
    cin>>n>>m>>k;
    for(int t = 0; t < n; t++){
        for(int i = 0; i <= k; i++){
            mn[i] = 1e7;
        }
        for(int i = 0; i < 510; i++){
            sdp[i] = 1e7;
        }
        scanf("%s", s+1);
        for(int i = 1; i <= m; i++){
            sum[i] =  sum[i-1] + (s[i] - '0');
        }
        if(sum[m] <= k) mn[sum[m]] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                int mid = sum[m] - (sum[j]-sum[i-1]);
                if(mid <= k) mn[mid] = min(mn[mid], j-i+1);
            }
        }
        for(int i = 0; i <= k; i++)
            for(int j = 0; j+i <= k; j++)
                sdp[i+j] = min(sdp[i+j], dp[i] + mn[j]);
        for(int i = 0; i <= k; i++)
            dp[i] = sdp[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i <= k; i++)
        ans = min(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}
