#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    vector<ll> r(n), c(m);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < m; i++) 
        cin >> c[i];
    ranges::sort(r);
    ranges::sort(c);
    int ri = 0, ci = 0;
    while (ri<n&&ci<m) {
        if (r[ri]<c[ci]) {
            ans += r[ri++]*ci;
        } else {
            ans += c[ci++]*ri;
        }
    }
    while (ri<n) {
        ans += r[ri++]*m;
    }
    while (ci<n) {
        ans += c[ci++]*m;
    }
    cout << ans << endl;
    return 0;
}#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    vector<ll> r(n), c(m);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < m; i++) 
        cin >> c[i];
    ranges::sort(r);
    ranges::sort(c);
    int ri = 0, ci = 0;
    while (ri<n&&ci<m) {
        if (r[ri]<c[ci]) {
            ans += r[ri++]*ci;
        } else if (r[ri]>c[ci]) {
            ans += c[ci++]*ri;
        } else if (ci > ri) {
            ans += c[ci++]*ri;
        } else {
            ans += r[ri++]*ci;
        }
    }
    while (ri<n) {
        ans += r[ri++]*m;
    }
    while (ci<m) {
        ans += c[ci++]*n;
    }
    cout << ans << endl;
    return 0;
}