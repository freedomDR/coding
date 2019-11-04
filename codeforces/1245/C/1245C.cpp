#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for(auto c:s)
    {
        if(c == 'm' || c == 'w')
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int n = s.size();
    int mod = 1e9+7;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1];
        if(s[i-1] == s[i-2] && (s[i-1] == 'u' || s[i-1] == 'n'))
            dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
	return 0;
}
