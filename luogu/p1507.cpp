#include<bits/stdc++.h>

using namespace std;

int dp[444][444], n;
int a[55], b[55], c[55], as, bs;
int main()
{
    cin >> as >> bs >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = as; j >= 0; j--)
        {
            for(int k = bs; k >= 0; k--)
            {
                if(j>=a[i]&&k>=b[i]) dp[j][k] = max(dp[j][k], dp[j-a[i]][k-b[i]]+c[i]);
            }
        }
    }
    cout << dp[as][bs] << endl;
    return 0;
}