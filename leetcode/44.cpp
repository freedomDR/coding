#include<bits/stdc++.h>
using namespace std;

// dp
bool sloveDP(string s, string p)
{
    int sLen = s.size(), pLen = p.size();
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1));
    dp[0][0] = true;
    for(int i = 0; i <= sLen; i++) {
        for(int j = 1; j <= pLen; j++) {
            if(p[j-1] == '*'){
                dp[i][j] = (i == 0 ? false : dp[i-1][j]) || dp[i][j-1];
            }else {
                dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    return dp[sLen][pLen];
}

// 双指针
bool sloveTwoPoint(string s, string p) 
{
    int si = 0, pi = 0, pres = -1, prep = -1;
    int sLen = s.size(), pLen = p.size();
    for(;si < sLen && pi < pLen;) {
        if(s[si] == p[pi] || p[pi] == '?') {
            si++; pi++; continue;
        }
        if(p[pi] == '*') {
            pres=si; prep=pi;pi++;continue;
        }
        if(prep == -1) return false;
        si = ++pres;
        pi = prep+1;
    }
    while(pi < pLen && p[pi] == '*') pi++;
    return pi==pLen;
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << sloveDP(s, p) << endl;
    cout << sloveTwoPoint(s, p) << endl;
    return 0;
}
