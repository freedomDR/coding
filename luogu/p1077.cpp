#include<bits/stdc++.h>

using namespace std;

//f[i][j] = sum(f[i-1][j-k]) {0<=k<=min(c[i],j)}

int dp[110], a[110];
int n, m;
int mod = 1000007;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j > 0; j--)
        {
            for(int k = 1; k <= min(a[i], j); k++)
            {
                dp[j] += dp[j-k];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}