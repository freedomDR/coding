#include <bits/stdc++.h>
using namespace std;
string slove(string s)
{
    int length = s.size();
    int st = 0, maxLen = 1;
    vector<vector<bool>> dp(length, vector<bool>(length));
    for(int r = 1; r < length; r++) {
        for(int l = 0; l < r; l++) {
            if(s[l] == s[r] && (r-l <= 2 || dp[l+1][r-1])){
                dp[l][r] = true;
                if(maxLen < (r-l+1)) {
                    st = l;
                    maxLen = r-l+1;
                }
            }
        }
    }
    return s.substr(st, maxLen);
}
int main()
{
    string s;
    cin >> s;
    cout << slove(s) <<endl;
    return 0;
}
