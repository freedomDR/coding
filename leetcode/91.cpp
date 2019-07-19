#include<bits/stdc++.h>
using namespace std;

int sloveDP(string s)
{
    if(s[0] == '0') return 0;
    int sLen = s.size();
    vector<int> dp(sLen+1);
    dp[0] = 1;
    for(int i = 0; i < int(s.size()); i++) {
        if(s[i] == '0') dp[i+1] = 0;
        else dp[i+1] = dp[i];
        if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) {
            dp[i+1] += dp[i-1];
        }
    }
    return dp.back();
}

int main()
{
    string s;
    cin >> s;
    cout << sloveDP(s) << endl;
    return 0;
}
