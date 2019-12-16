#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<bool> use(26, false);
    for(int i = 0; i < k; i++)
    {
        char c; cin >> c;
        use[c-'a'] = true;
    }
    long long ans = 0;
    long long len = 0;
    for(auto c:s)
    {
        if(use[c-'a']) len++;
        else
        {
            ans += (len+1)*len/2;
            len = 0;
        }
    }
    ans += (len+1)*len/2;
    cout << ans << endl;
    return 0;
}
