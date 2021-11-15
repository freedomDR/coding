#include<bits/stdc++.h>

using namespace std;

struct Dish
{
    long long a;
    long long b;
};

int main()
{
    #ifdef LOCAL
        freopen("./codeforces/p1067G.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<Dish> arr(n);
        for(auto & v:arr)
            cin >> v.a >> v.b;
        long long sum_a = 0, sum_b = 0, max_ea = 0, max_eb=0;
        for(auto & v:arr)
        {
            sum_a += v.a;
            sum_b += v.b;
            max_ea += min(v.a, m);
            max_eb += min(v.b, m);
        }
        long long l = (sum_a-max_ea)-(sum_b-(n*m-max_ea));
        long long r = (sum_a-(n*m-max_eb))-(sum_b-max_eb);
        // cout << l << " " << r << endl;
        long long ans = 0, ea = 0, eb = 0;
        if(r < 0) 
        {
            ea = m*n-max_eb;
            eb = max_eb;
            ans = -r;
        }
        else if (l > 0)
        {
            ea = max_ea;
            eb = m*n-ea;
            ans = l;
        }
        else
        {
            if(sum_a-sum_b < 0)
            {
                ans = 0;
                eb = (sum_b-sum_a) + (m*n-(sum_b-sum_a))/2;
                ea = (m*n)-eb;
            }
            else
            {
                ans = 0;
                ea = (sum_a-sum_b) + (m*n-(sum_a-sum_b))/2;
                eb = (m*n)-ea;
            }
        }
        cout << abs(sum_a-ea-sum_b+eb) << endl;
        for(auto & v:arr)
        {
            long long v1 = min(v.a, m);
            v1 = min(ea, v1);
            long long v2 = m-v1;
            long long v22 = eb - (max_eb-min(v.b, m));
            if(v22 > v2)
            {
                v2 = v22;
                v1 = m-v2;    
            }
            cout << v1 << " " << v2 << endl;
            ea -= v1; eb -= v2;
            max_eb -= min(v.b, m);
        }
    }
    return 0;
}