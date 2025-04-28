#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (auto & v:arr) cin >> v;
    long long ans = 0, tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += arr[i];
        ans = max(ans, tmp);
        if (i >= 9) tmp -= arr[i-10+1];
    }
    cout << ans << endl;
    return 0;
}