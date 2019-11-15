#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(auto &v:a) cin >> v;
        int m; cin >> m;
        vector<int> maxv(n+1, INT_MIN);
        vector<pair<int, int>> h(m);
        for(auto &v:h) cin >> v.second >> v.first;
        sort(h.begin(), h.end());
        for(int i = m-1, tmpmax = -1; i >= 0; i--)
        {
            tmpmax = max(tmpmax, h[i].second);
            maxv[h[i].first] = tmpmax;
        }
        for(int i = n, tmp = INT_MIN; i >= 0; i--)
        {
            tmp = max(tmp, maxv[i]);
            maxv[i] = tmp;
        }
        /* for_each(maxv.begin(), maxv.begin()+4, [](auto &v){cout << v << " ";}); */
        /* cout << endl; */
        int ans = 0, pos = 0;
        while(pos < n)
        {
            int maxa = a[pos], len = 1;
            /* cout << maxa << " " << maxv[len] << endl; */
            while(maxa <= maxv[len])
            {
                len++;
                pos++;
                if(pos == n) break;
                maxa = max(maxa, a[pos]);
            /* cout << maxa << " " << maxv[len] << endl; */
            }
            if(len == 1) break;
            ans++;
        }
        if(pos == n) cout << ans << endl;
        else cout << "-1" << endl;

    }
    return 0;
}
