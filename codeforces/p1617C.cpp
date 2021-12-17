#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> arr(n), f(n+1);
        for(auto &v:arr) cin >> v;
        int ans = 0;
        bool ok = true;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++)
        {
            if(arr[i]>=1 && arr[i] <= n && f[arr[i]]==0)
            {
                f[arr[i]] = 1;
                arr[i] = -1;    
            }
        }
        for(int i = 0, j = 1; i < n; i++)
        {
            if(arr[i] != -1)
            {
                while(f[j]==1) j++;
                if((arr[i]-1)/2<j)
                {
                    ok = false;
                    break;
                }
                ans++;
                f[j] = 1;
            }
        }
        if(ok) cout << ans << endl;
        else cout << "-1" << endl;
    }
    return 0;
}
