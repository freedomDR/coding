#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(2, vector<int>(m+5));
    int p = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> dp[p%2][j];
            dp[p%2][j] += max(dp[(p+1)%2][j], max(dp[(p+1)%2][j-1], dp[(p+1)%2][j+1]));
        }
        p++;
    }
    cout << max(dp[(p+1)%2][m/2], max(dp[(p+1)%2][m/2+1], dp[(p+1)%2][m/2+2])) << endl;

    return 0;
}
