#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> arr(n), dp1(n+5), dp2(n+5);
    for(auto &v:arr) cin >> v;
    arr.resize(n+5);
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        dp1[i] = max(dp1[i], 1);
        if(arr[i] < arr[i+1])
        {
            dp1[i+1] = max(dp1[i]+1, dp1[i+1]);
            dp2[i+1] = max(dp2[i]+1, dp2[i+1]);
        }
        if(arr[i] < arr[i+2])
        {
            dp2[i+2] = max(dp2[i+2], dp1[i]+1);
        }
        ans = max(ans, dp1[i]);
        ans = max(ans, dp2[i]);
    }
    cout << ans << endl;
    return 0;
}
