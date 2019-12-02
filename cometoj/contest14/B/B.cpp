#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> l(4, n),r(4, 0);
        string p = "pink";
        int pos = 0;
        while(pos < n && s[pos] != p[1]) {if(s[pos] != p[0]) ;else {l[0] = min(l[0], pos);r[0] = max(r[0], pos);} pos++;}
        while(pos < n && s[pos] != p[2]) {if(s[pos] != p[1]);else{l[1] = min(l[1], pos);r[1] = max(r[1], pos);} pos++;}
        while(pos < n && s[pos] != p[3]) {if(s[pos] != p[2]);else {l[2] = min(l[2], pos);r[2] = max(r[2], pos);} pos++;}
        while(pos < n) {if(s[pos] != p[3]);else {l[3] = min(l[3], pos);r[3] = max(r[3], pos);} pos++;}
        int ans = -1;
        for(int i = 1; i < 4; i++)
        {
            if(l[i] == n || l[i-1] == n) {ans = -1; break;}
            ans = max(ans, r[i] - l[i-1]-1);
        }
        cout << ans << endl;
    }
    return 0;
}
