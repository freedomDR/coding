#include<bits/stdc++.h>
using namespace std;

int slove(vector<vector<int>>& a) 
{
    int m = a.size(), n = a[0].size();
    vector<long long> dp(n);
    for(int i = 0; i < m; i++) {
        if(a[i][0] == 1) dp[0] = 0;
        else if(i == 0) dp[0] = 1;
        else ;
        for(int j = 1; j < n; j++) {
            dp[j] = a[i][j] == 1 ? 0 : (dp[j]+dp[j-1]);
        }
    }
    return dp[n-1];
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
