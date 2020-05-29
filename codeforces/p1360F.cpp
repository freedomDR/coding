#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for(auto &it:s) cin >> it;
        string ans = "";
        for(int i = 0; i < m && ans == ""; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                string tmp = s[0];
                tmp[i] = 'a'+j;
                bool ok = true;
                for(int k = 0; k < n; k++)
                {
                    int diff = 0;
                    for(int p = 0; p < m; p++)
                        if(tmp[p] != s[k][p]) diff++;
                    if(diff > 1) {ok = false; break;}
                }
                if(ok) {ans = tmp; break;}
            }
        }
        if(ans == "") cout << "-1" << endl;
        else cout << ans << endl;
    }
    return 0;
}