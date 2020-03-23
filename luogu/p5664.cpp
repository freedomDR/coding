#include<bits/stdc++.h>

using namespace std;

int a[110][2010], A[110], B[110], mod=998244353;
long long ans, sum, dp[110][220], s[110];
int main()
{
    int n, m;
    cin >> n >> m;
    ans = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i] += a[i][j];
            s[i] %= mod;
        }
        ans = (ans*(s[i]+1))%mod;
    }
    for(int col = 1; col <= m; col++)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            A[i] = a[i][col];
            B[i] = (s[i]-a[i][col]+mod)%mod;
        }
        dp[0][n] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = n-i; j <= n+i; j++)
            {
                dp[i][j] = (dp[i-1][j])+(dp[i-1][j+1]*B[i])%mod;
                if(j-1>=0) dp[i][j] = (dp[i][j]+dp[i-1][j-1]*A[i])%mod;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            sum = (sum+dp[n][i+n])%mod;
        }
    }
    cout << (ans-1-sum+mod)%mod << endl;
    return 0;
}