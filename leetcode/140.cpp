#include<bits/stdc++.h>
using namespace std;

vector<string> sloveDP(string s, vector<string>& w)
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
                continue;
            }
        }
        /* cout << dp[i] << " " << ans[i].size() << endl; */
    }
    if(dp.back() == false) return vector<string>{};
    vector<string> res;
    std::function<void(string, int)> dfs;
    dfs = [&res, &dp, &s, &dict, &dfs](string tmp, int st)->void{
        if(st == int(s.size())){
            res.push_back(tmp);
            return;
        }
        for(int i = st; i < int(s.size()); i++) {
            if(dp[i]){
                for(int j = 0, ii = s[i]-'a'; j < int(dict[ii].size()); j++) {
                    if(s.substr(st, i-st+1) == dict[ii][j])
                        dfs(tmp+(tmp==""?"":" ")+s.substr(st,i-st+1), i+1);
                }
            }
        }
    };
    dfs("", 0);
    return res;
}

int main()
{
    int n;
    string s;
    cin >> s >> n;
    vector<string> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    auto res = sloveDP(s, w);
    for(auto v:res)
        cout << v << endl;
    return 0;
}
