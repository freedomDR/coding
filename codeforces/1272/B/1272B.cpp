#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        string s; cin >> s;
        map<char, int> cnt;
        for(auto c:s) cnt[c]++;
        int r = min(cnt['L'], cnt['R']);
        int l = min(cnt['U'], cnt['D']);
        if(l == 0 && r == 0) {cout << "0" << endl;continue;}
        else if(r == 0)
        {
            cout << "2" << endl;
            cout << "UD" << endl;
            continue;
        }else if(l == 0)
        {
            cout << "2" << endl;
            cout << "RL" << endl;
            continue;
        }else
        {
            cout << (r+l)*2 << endl;
            string ans = "";
            ans += string(r, 'L');
            ans += string(l, 'D');
            ans += string(r, 'R');
            ans += string(l, 'U');
            cout << ans << endl;
            continue;
        }
    }
    return 0;
}
