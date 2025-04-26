#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = 1;
    int suffix_sum = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (it->second+suffix_sum >= m) {
            ans = max(ans, it->second);
        } else {
            suffix_sum += it->second;
        }
    }
    cout << min(ans, m) << endl;
    return 0;
}