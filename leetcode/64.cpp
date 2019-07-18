#include<bits/stdc++.h>
using namespace std;

int slove(vector<vector<int>>& a) 
{
    int m = a.size(), n = a[0].size();
    vector<long long> dp(n+1, INT_MAX);
    dp[1] = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j] = min(dp[j], dp[j-1]) + a[i][j-1];
        }
        /* for(int j = 0; j < n; j++) cout << dp[j] <<" "; */
        /* cout << endl; */
    }
    return dp[n];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << slove(a) << endl;
    return 0;
}
