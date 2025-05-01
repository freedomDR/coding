#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    priority_queue<pii, vector<pii>, greater<pii>> pa, pab;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        pa.emplace(a[i], i);
        pab.emplace(a[i]+b[i], i);
    }
    ll ans = 0;
    vector<bool> vis(n+1);
    ll cur = pa.top().first;
    vis[pa.top().second] = 1;
    int last = b[pa.top().second];
    for (int i = 1; i < n; i++) {
        while (vis[pa.top().second]) pa.pop();
        while (vis[pab.top().second]) pab.pop();
        int k = 0;
        if (pab.top().first < pa.top().first+last) k = pab.top().second;
        else k = pa.top().second;
        vis[k] = 1;
        cur += a[k] + min(last, b[k]);
        ans += cur;
        last = max(last, b[k]);
    }
    cur += last;
    ans += cur;
    cout << ans << endl;
    return 0;
}