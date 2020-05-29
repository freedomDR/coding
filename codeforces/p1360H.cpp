#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> t;
        for(int i = 0 ; i < n; i++)
        {
            string s; cin >> s;
            long long tmp = 0;
            for(long long j = m-1, base = 1; j >= 0; j--, base *= 2)
            {
                if(s[j]=='1') tmp += base;
            }
            t.push_back(tmp);
        }
        sort(t.begin(), t.end());
        string ans(m, '0');
        long long pre = 0, need = ((1ll<<m)-n-1)/2 + 1, l = 0;
        for(int i = 0; i < n; i++)
        {
            if(pre+need-1<t[i])
            {
                l = pre+need-1;
                break;
            }
            need -= (t[i]-pre);
            pre = t[i]+1;
        }
        if(need > 0) l = pre+need-1;
        for(int i = 0; i < m; i++)
        {
            if((l&(1ll<<i))) ans[i] = '1';
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}