#include<bits/stdc++.h>

using namespace std;

int dp[1010], temp[1010], n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            int v;
            cin >> v;
            temp[j] = max(dp[j-1], dp[j]) + v;
        }
        swap(dp, temp);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}