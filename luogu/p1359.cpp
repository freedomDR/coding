#include<bits/stdc++.h>

using namespace std;

int dp[210], e[210][210], n;
int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
         cin >> e[i][j];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i-1; j >= 1; j--)
        {
            dp[i] = min(dp[i], dp[j]+e[j][i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}