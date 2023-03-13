#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    map<char, int> mp = {{'M', 0}, {'m', 0}, {'e', 1}, {'E', 1}, {'O', 2}, {'o', 2}, {'W', 3}, {'w',3}};
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int pre = -1, ok = 1;
        for(auto & c: s)
        {
            if(mp.count(c) == 0 || (mp[c] != pre && mp[c]-1 != pre))
            {
                ok = 0;
                break;
            }
            pre = mp[c];
        }
        if(pre != 3) 
            ok = 0;
        cout << (ok?"YES":"NO") << "\n";
    }
    return 0;
}
