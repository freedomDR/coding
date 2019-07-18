#include<bits/stdc++.h>
using namespace std;

int slove(int m, int n) 
{
    vector<int> dp(n);
    for(int i = 0; i < m; i++) {
        dp[0] = 1;
        for(int j = 0; j < n; j++) {
            dp[j] = dp[j] + (j==0?0:dp[j-1]);
        }
    }
    return dp[n-1];
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << slove(m, n) << endl;
    return 0;
}
