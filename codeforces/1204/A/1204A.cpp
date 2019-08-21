#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string t = "1";
    int ans = 0;
    while(t.size() <= s.size() && t < s) {
        t += "00";
        ans++;
    }
    cout << ans << endl;
}
