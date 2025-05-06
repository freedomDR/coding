#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 inf = 1e18;

i64 get(const vector<i64> & arr) {
    i64 tmp = -inf;
    i64 ans = -inf;
    for (auto & v:arr) {
        tmp = max(0ll, tmp)+v;
        ans = max(ans, tmp);
    }
    return ans;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        i64 n, k; cin >> n >> k;
        string s;
        vector<long long> arr(n);
        cin >> s;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (s[i] == '0') arr[i] = -inf;
        }
        i64 res = get(arr);
        if (res > k) {
            cout << "NO" << endl;
            continue;
        }
        int pos = s.find('0');
        if (pos == string::npos) {
            if (res == k) {
                cout << "YES" << endl;
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            arr[pos] = inf;
            res = get(arr);
            arr[pos] -= (res-k);
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) 
                cout << arr[i] << " ";
            cout << endl;
        }
    }
    return 0;
}