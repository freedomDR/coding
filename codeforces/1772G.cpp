#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void slove() {
    int n, x, y;
    std::cin >> n >> x >> y;
    vector<ll> arr(n), t(n), b(n);
    for (auto &i : arr) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        if (i > 0 && b[i - 1] > arr[i]) {
            t[i] = t[i - 1];
            b[i] = b[i - 1] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        slove();
    }
    return 0;
}
