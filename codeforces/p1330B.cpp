#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &it:a) cin >> it;
        vector<int> l(n), r(n);
        vector<bool> f(n+1);
        for(int i = 0, cnt = 0, maxv=-1; i < n; i++)
        {
            if(f[a[i]]) break;
            f[a[i]] = true;
            cnt++;
            maxv=max(maxv, a[i]);
            if(maxv==cnt) l[i] = 1;
        }
        fill(f.begin(), f.end(), false);
        for(int i = n-1, cnt = 0, maxv=-1; i >= 0; i--)
        {
            if(f[a[i]]) break;
            f[a[i]] = true;
            cnt++;
            maxv=max(maxv, a[i]);
            if(maxv==cnt) r[i]=1;
        }
        // for(auto it:l) cout << it << " ";
        // cout << endl;
        // for(auto it:r) cout << it << " ";
        // cout << endl;
        vector<pair<int, int>> ans;
        for(int i = 0; i < n-1; i++)
        {
            if(l[i]==1&&r[i+1]==1) 
            {
                ans.push_back(make_pair(i+1, n-i-1));
            }
        }
        cout << ans.size() << endl;
        for(auto &it:ans) cout << it.first << " " << it.second << endl;
    }
    return 0;
}