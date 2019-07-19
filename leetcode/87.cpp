#include <bits/stdc++.h>
using namespace std;

bool sloveDP(string s1, string s2)
{
    int s1Len = s1.size(), s2Len = s2.size();
    if(s1Len != s2Len ) return false;
    if(s1 == s2) return true;
    bool dp[s1Len+1][s1Len][s2Len];
    std::memset(dp, false, sizeof dp);
    for(int len = 1; len <= s1Len; len++){
        for(int p1 = 0; p1+len <= s1Len; p1++) {
            for(int p2 = 0; p2+len <= s2Len; p2++){
                if(len == 1) {
                    dp[len][p1][p2] = s1[p1] == s2[p2];
                }else {
                    for(int k = 1; k < len && !dp[len][p1][p2]; k++) {
                        dp[len][p1][p2] = (dp[k][p1][p2]&&dp[len-k][p1+k][p2+k])||(dp[k][p1][p2+len-k]&&dp[len-k][p1+k][p2]);
                    }
                }
            }
        }
    }
    return dp[s1Len][0][0];
}

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << sloveDP(s1, s2) << endl;
    return 0;
}
