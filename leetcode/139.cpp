#include<bits/stdc++.h>
using namespace std;

bool sloveDP(string s, vector<string>& w)
{
    vector<vector<string>> dict(26);
    vector<bool> dp(s.size());
    for(int i = 0; i < int(w.size()); i++) {
        dict[w[i].back()-'a'].push_back(w[i]);
    }
    for(int i = 0; i < int(s.size()); i++) {
        for(int j = 0, ii = s[i]-'a'; j < int(dict[ii].size()); j++) {
            int p = i - dict[ii][j].size()+1;
            /* cout << i<< " " << p << endl; */
            if(p < 0) continue;
            if((p == 0 || dp[p-1]) && s.substr(p, i-p+1) == dict[ii][j]) {
                dp[i] = true;
                break;
            }
        }
        /* cout << dp[i] << endl; */
    }
    return dp.back();
}

int main()
{
    int n;
    string s;
    cin >> s >> n;
    vector<string> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    cout << sloveDP(s, w) << endl;
    return 0;
}
