#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> cnt(105, 0);
    for (int i = 0; i < n; ++i) {
        cnt[arr[i]]++;
    }
    vector<int> ans(105, n + 1);
    int prefix_sum = 0;
    for (int i = 1; i <= 100; i++) {
        prefix_sum += cnt[i];
        int greater_x = n - prefix_sum;
        ans[i] = greater_x;
        vector<int> cnt2(105, 0);
        for (int k = n - 1; k >= 0; k--) {
            if (arr[k] <= i) continue;
            int must_use = accumulate(cnt2.begin() + arr[k] + 1, cnt2.end(), 0);
            ans[i] = min(ans[i],
                         must_use + (greater_x - 1 -
                                     accumulate(cnt2.begin(), cnt2.end(), 0)));
            cnt2[arr[k]]++;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}