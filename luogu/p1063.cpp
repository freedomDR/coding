#include<bits/stdc++.h>

using namespace std;

long long a[222], dp[222][222], n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1, j = i+len-1; j < 2*n; i++, j++)
        {
            for(int k = i; k < j; k++)
            {
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+(a[i]*a[k+1]*a[j+1]));
            }
        }
    }
    long long ans = 0;
    for(int i = 1, j = i+n-1; j < 2*n; i++, j++)
        ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}