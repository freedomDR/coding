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
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if ((i==0||arr[i]>arr[i-1])&&(i==n-1||arr[i]>arr[i+1]))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}