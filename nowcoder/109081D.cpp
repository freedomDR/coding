#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> f(17);
    for (int i = 1; i < 17; i++)
        f[i] = (1<<i)-1;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int len = s.size(), tmp = 0;
        for (int j = 0; j < len; j++) {
            if (s[j]=='1') tmp |= (1<<j);
        }
        f[len] &= tmp;
    }
    auto check = [&](int x) {
        for (int i = 1; i <= 16; i++) {
            int m = x%i;
            if (f[i]>>m&1) continue;
            return false;
        }
        return true;
    };
    for (int i = 0; i < 1000000; i++) {
        if (check(i)) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}