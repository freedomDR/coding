#include<bits/stdc++.h>
using namespace std;

int kmp(string s) {
    vector<int> next(s.size());
    next[0] = -1;
    int pos = 1, cnd = 0;
    while(pos < s.size()) {
        if(s[pos] == s[cnd]) 
            next[pos] = next[cnd];
        else {
            next[pos] = cnd;
            cnd = next[cnd];
            while(cnd >= 0 && s[pos] != s[cnd]) cnd = next[cnd];
        }
        pos++; cnd++;
    }
    return next.back();
}

int main()
{
    int n; cin >> n;
    string ans, s;
    while(n--) {
        if(ans == "") {
            cin >> ans; continue;
        }
        cin >> s;
        string t = s;
        t += "#";
        int len = min(ans.size(), s.size());
        t.insert(t.end(), ans.end()-len, ans.end());
        t += "$";
        int x = kmp(t);
        while(x--) {
            ans.pop_back();
        }
        ans.insert(ans.end(), s.begin(), s.end());
    }
    cout << ans << endl;
    return 0;
}
