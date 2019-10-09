#include<bits/stdc++.h>
using namespace std;
int xs[5005], ys[5005], dp[5005][1001];
int main()
{
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    for(int i = 1; i <= n; i++)
    {
        cin >> xs[i] >> ys[i];
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for(int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(a+b>=xs[i]&&j>=ys[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-ys[i]]+1);
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}
