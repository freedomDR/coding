#include <bits/stdc++.h>
using namespace std;

// dp 解法
int slove(string s) 
{
    int ans = 0;
    vector<int> dp(s.size());
    for(int i = 0; i < int(s.size()); i++) {
        if(i == 0 || s[i] == '(') continue;
        if(s[i-1] == '(') dp[i] = dp[max(0, i-2)] + 2;
        else {
            int pos = i-dp[i-1]-1;
            if(pos >= 0 && s[pos] == '(') dp[i] = dp[i-1]+2+(pos == 0?0:dp[pos-1]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << slove(s) << endl;
    return 0;
}
