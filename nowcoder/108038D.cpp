#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = -1;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        for (auto [k, v] : cnt) {
            if (!cnt.count(k-1)) {
                ans++;
                if (!cnt.count(k+1)) {
                    ans += v-1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}