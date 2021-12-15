#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for(auto &v:arr) cin >> v;
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0; i < n-2*k; i++)
            ans += arr[i];
        int maxSame = 0;
        int pos = n-2*k;
        while(pos < n)
        {
            int cnt = 1;
            while(pos+1<n && arr[pos]==arr[pos+1]) {cnt++;pos++;}
            maxSame = max(maxSame, cnt);
            pos++;
        }
        cout << ans+((maxSame>k)?(maxSame-k):0) << endl;
    }
    return 0;
}
