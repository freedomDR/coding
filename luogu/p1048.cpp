#include<bits/stdc++.h>

using namespace std;

int dp[1010], t, m, cost[110], v[110];
int main()
{
    cin >> t >> m;
    for(int i = 1; i <= m; i++)
        cin >> cost[i] >> v[i];
    for(int i = 1; i <= m; i++)
    {
        for(int j = t; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-cost[i]]+v[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}