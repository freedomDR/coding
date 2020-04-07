#include<bits/stdc++.h>

using namespace std;

int dp[1005][1005], n;
int main()
{
    string s;
    cin >> s;
    s = " "+s;
    n = s.size();
    for(int len = 2; len < n; len++)
    {
        for(int i = 1, j = i+len-1; j <= n; i++, j++)
        {
            dp[i][j] = min(dp[i][j-1]+1, dp[i+1][j]+1);
            if(s[i]==s[j]) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i+1][j-1]+2);//i+1>j-1 == 0
        }
    }
    cout << dp[1][n-1] << endl;
    return 0; 
}