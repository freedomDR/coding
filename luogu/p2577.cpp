#include<bits/stdc++.h>

using namespace std;

const int N = 205;
int dp[N][N*N], n, a[N], b[N], p[N], pos[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for(int i = 1; i <= n; i++) pos[i] = i;
    sort(pos+1, pos+n+1, [](int i, int j){return b[i]>b[j];});
    for(int i = 1; i <= n; i++) p[i] = p[i-1]+a[pos[i]];
    //dp[i][j] dp[i-1][j-]
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= p[i]; j++)
        {
            if(j>=a[pos[i]]) dp[i][j] = min(dp[i][j], max(dp[i-1][j-a[pos[i]]], j+b[pos[i]]));//1
            dp[i][j] = min(dp[i][j], max(dp[i-1][j], p[i]-j+b[pos[i]]));//2
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= p[n]; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
