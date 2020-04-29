#include<bits/stdc++.h>

using namespace std;
struct T
{
    int a, b;
    bool operator < (const T &t2)
    {
        return a < t2.a;
    }
}t[100005];
int n, dp[100005], ans=INT_MAX;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i].a >> t[i].b;
    sort(t+1, t+n+1);
    for(int i = 1; i <= n; i++)
    {
        T tt;
        tt.a = t[i].a-t[i].b;
        tt.b = 0;
        int p = lower_bound(t+1, t+i, tt)-t;
        if(p-1>=0)dp[i] = dp[p-1]+1;
        else dp[i] = 1;
        ans = min(ans, n-dp[i]);
    }
    cout << ans << endl;
    return 0;
}