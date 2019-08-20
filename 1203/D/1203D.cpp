#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    vector<int> l(t.size()), r(t.size());
    int pos = 0;
    int ans = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(pos < (int)t.size() && s[i] == t[pos]) {
            l[pos] = i;pos++;
        }
        if(pos == (int)t.size()) {
            ans = max(ans, (int)s.size()-i-1);
            break;
        }
    }
    pos = t.size()-1;
    for(int i = (int)s.size()-1; i >= 0; i--) {
        if(pos >= 0 && s[i] == t[pos]) {
            r[pos] = i;pos--;
        }
        if(pos == -1) {
            ans = max(ans, i);
        }
    }
    for(int i = 0; i+1 < (int)t.size(); i++) {
        ans = max(ans, r[i+1]-l[i]-1);
    }
    cout << ans << endl;
    return 0; 
}
