#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    vector<int> a(n), b(n), a_pos(n + 1), b_pos(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a_pos[a[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b_pos[b[i]] = i + 1;
    }
    auto cal = [](int ll, int rr) {
        if (ll > rr) return 0ll;
        return 1ll * (rr - ll + 2) * (rr - ll + 1) / 2;
    };
    auto cal2 = [](int l1, int l2, int r1, int r2) {
        return 1ll * (l2 - l1 + 1) * (r2 - r1 + 1);
    };
    long long ans = 0;
    // mex = 1
    int l = min(a_pos[1], b_pos[1]);
    int r = max(a_pos[1], b_pos[1]);
    ans += cal(1, l - 1);
    ans += cal(l + 1, r - 1);
    ans += cal(r + 1, n);
    // mex = 2...n
    for (int i = 2; i <= n; i++) {
        int nl = min(a_pos[i], b_pos[i]);
        int nr = max(a_pos[i], b_pos[i]);
        if (r < nl) {
            ans += cal2(1, l, r, nl - 1);
        }
        if (l > nl && r < nr) {
            ans += cal2(nl + 1, l, r, nr - 1);
        }
        if (l > nr) {
            ans += cal2(nr + 1, l, r, n);
        }
        l = min(l, nl);
        r = max(r, nr);
    }
    ans += 1;
    std::cout << ans << std::endl;
    return 0;
}
