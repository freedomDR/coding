#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353;
int main()
{
    string s, t;
    cin >> s >> t;
    int sn = s.size(), tn = t.size();
    vector<vector<long long>> dp(sn, vector<long long>(sn));
    for(int i = 0; i  < tn; i++) 
        if(t[i]==s[0]) dp[i][i] = 2;
    for(int i = tn; i < sn; i++)
        dp[i][i] = 2;
    for(int len = 2; len <= sn; len++)
    {
        for(int i = 0, j = i+len-1; j < sn; i++, j++)
        {
            if(i>=tn||t[i] == s[len-1])
                dp[i][j] += dp[i+1][j];
            dp[i][j] %= mod;
            if(j>=tn||t[j] == s[len-1])
                dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    long long ans = 0;
    for(int i = tn-1; i < sn; i++) ans = (ans+dp[0][i])%mod;
    cout << ans << endl;
    return 0;
}