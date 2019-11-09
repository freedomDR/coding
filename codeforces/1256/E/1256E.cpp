#include <bits/stdc++.h>
using namespace std;

typedef struct A
{
    int v;
    int p;
    bool operator < (const A &b)
    {
        return v < b.v;
    }
}A;

int main()
{
    int n; cin >> n;
    vector<A> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].v;
        a[i].p = i;
    }
    sort(a.begin(), a.end());
    vector<int> dp(n+1, 1e9), pos(n+1);
    dp[0] = 0;
    for(int i = 3; i <= n; i++)
    {
        for(int j = max(0, i-6); j+3 <= i; j++)
        {
            if(dp[i] > dp[j]+a[i-1].v - a[j].v)
            {
                dp[i] = min(dp[i], dp[j]+a[i-1].v-a[j].v);
                pos[i] = j;
            }   
        }
    }
    int p = n, cnt = 1;
    vector<int> ans(n);
    while(p > 0)
    {
        for(int i = 0; i < p-pos[p]; i++)
        {
            ans[a[p-1-i].p] = cnt;
        }
        cnt++;
        p = pos[p];
    }
    cout << dp[n] << " " << cnt-1 << endl;
    for(auto v:ans) cout << v << " ";
    return 0;
}
