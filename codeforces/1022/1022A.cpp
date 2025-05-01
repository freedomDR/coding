#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sums = 0;
        for (int l = 1, r = n; l < r; l++, r--) {
            sums += (r-l);
        }
        cout << (n==1?1:sums+1) << endl;
    }
    return 0;
}