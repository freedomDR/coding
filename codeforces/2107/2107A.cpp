#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        unordered_set<int> s(arr.begin(), arr.end());
        if (s.size() == 1) {
            cout << "NO" << endl;
            continue;
        }
        int max_v_pos = max_element(arr.begin(), arr.end())-arr.begin();
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << (i==max_v_pos?1:2) << " ";
        }
        cout << endl;
    }
    return 0;
}