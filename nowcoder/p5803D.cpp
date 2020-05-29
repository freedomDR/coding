#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    map<string, int> cnt;
    vector<string> s(n+1);
    s.push_back("");
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for(int p = 0; p < k; p++)
        {
            for(int j = 1; p+j <= k; j++)
                cnt[s[i].substr(p, j)]++;
        }
    } 
    int q; cin >> q;
    while(q--)
    {
        int x, len; cin >> x >> len;
        map<string, int> tmp;
        for(int i = 0; i+len <= k; i++)
        {
            tmp[s[x].substr(i, len)]++;   
        }
        int ans = 0;
        for(int i = 0; i +len <= k; i++)
        {
            string ss = s[x].substr(i, len);
            ans += cnt[ss]-tmp[ss];
        }
        cout << ans*len << endl;
    }
    return 0;
}