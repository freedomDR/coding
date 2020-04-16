#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<int> r(nr), g(ng), b(nb);
        for(auto &it:r) cin >> it;
        for(auto &it:g) cin >> it;
        for(auto &it:b) cin >> it;
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        long long ans = LLONG_MAX;
        auto cal = [](long long x, long long y, long long z)
        {
            return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
        };
        auto slove = [&](auto a, auto b, auto c)
        {
            int i = 0, j = 0;
            for(auto y:b)
            {
                while(i<(int)a.size()&&a[i]<=y) i++;
                while(j<(int)c.size()&&c[j]<y) j++;
                if(i>0&&j < (int)c.size())
                {
                    ans = min(ans, cal(a[i-1], y, c[j]));
                }
            }
        };
        slove(r, g, b);
        slove(r, b, g);
        slove(g, r, b);
        slove(g, b, r);
        slove(b, g, r);
        slove(b, r, g);
        cout << ans << endl;
    }
    return 0;
}