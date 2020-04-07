#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> f(1001, 0);
    for(int i = 2; i <= 1000; i++)
    {
        if(f[i]) continue;
        for(int j = i; j <= 1000; j+=i)
        {
            f[j] = i;
        }
    }
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &it:a) cin >> it;
        map<int, int> ans;
        map<int, vector<int>> mp;
        for(auto it:a)
        {
            mp[f[it]].push_back(it);
        }
        int cnt = 0;
        for(auto &it:mp)
        {
            cnt++;
            for(auto &v:it.second)
            {
                ans[v] = cnt;
            }
        }
        cout << cnt << endl;
        for(auto it:a) cout << ans[it] << " ";
        cout << endl;
    }
    return 0;
}