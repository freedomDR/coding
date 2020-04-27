#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> arr;
        for(int i = 0; i < n; i++)
        {
            int v; cin >> v;
            arr.push_back(v);
        }
        sort(arr.begin(), arr.end());
        int ans = n;
        vector<int> dp(arr[n-1]+1);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            if(dp[arr[i]]) {ans--;continue;}
            for(int j = 0; j+arr[i] <= arr[n-1]; j++)
                dp[j+arr[i]] |= dp[j];
        }
        cout << ans << endl;
    }
    return 0;
}