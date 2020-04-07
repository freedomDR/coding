#include<bits/stdc++.h>

using namespace std;

int dp[1<<22], n, e[23][23];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> e[i][j];
        }
    }
    for(int i = 1; i < (1<<n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i&(1<<j)) == 0) continue;
            int sums = 0;
            for(int k = 0; k < n; k++)
            {
                if((i&(1<<k))!=0) continue;
                sums += e[j][k];
            } 
            dp[i] = max(dp[i-(1<<j)]+sums*sums, dp[i]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}