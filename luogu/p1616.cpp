
#include<bits/stdc++.h>

using namespace std;

int dp[101000], t, m, cost[10100], v[10100];
int main()
{
    cin >> t >> m;
    for(int i = 1; i <= m; i++)
        cin >> cost[i] >> v[i];
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j+cost[i]<=t; j++)
        {
            dp[j+cost[i]] = max(dp[j]+v[i], dp[j+cost[i]]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}