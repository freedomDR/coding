#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(auto &it:a) cin >> it;
        sort(a.begin(), a.end());
        int ans = 1;
        for(int i = 1, pos = 0; i <= n && pos < n; i++)
        {
            while(a[pos] < i) pos++;
            if(pos == n) continue;
            if(n-pos >= i) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}
