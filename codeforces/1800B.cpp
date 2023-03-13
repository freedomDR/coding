#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        map<char, int> mp;
        for(auto & c : s)
        {
            mp[c]++;
        }
        for(int i = 0; i < 26; i++)
        {
            char c1 = 'a'+i, c2 = 'A'+i;
            ans += min(mp[c1], mp[c2]);
            int diff = abs(mp[c1] - mp[c2]);
            if(diff == 0 || k <= 0)
                continue;
            diff /= 2;
            ans += min(diff, k);
            k -= diff;
        }
        cout << ans << endl;
    }
    return 0;
}
