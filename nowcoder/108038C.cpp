#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto & v : arr) { cin >> v; }
        int ans = 0, max_v = arr[0];
        for (int i = 1; i < n; i++) {
            if (max_v > arr[i])
                ans = max(ans, max_v + arr[i]);
            max_v = max(max_v, arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}