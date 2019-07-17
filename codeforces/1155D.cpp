#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    ll dp[n+1][3][3];
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k] = LLONG_MIN;
    dp[0][0][0] = 0;
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
            {
                if(i < n)
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + ll(j == 1?a[i]:0)*ll(k == 1?x:1));
                if(k < 2)
                    dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
                if(j < 2)
                    dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
            }
    cout<<dp[n][2][2]<<endl;
    return 0;
}
