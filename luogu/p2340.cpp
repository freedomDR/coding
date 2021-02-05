#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 8e5+10;
int dp[maxn], cnt[maxn];
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        x[i] += 1000;
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = maxn-1; j >= x[i]; --j)
        {   if(dp[j-x[i]]+y[i] > dp[j] ||(dp[j] == dp[j-x[i]]+y[i] && cnt[j] > cnt[j-x[i]]+1)) 
            {
                dp[j] = dp[j-x[i]]+y[i];
                cnt[j] = cnt[j-x[i]]+1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < maxn; ++i)
    {
        if(dp[i] >= 0 && i-1000*cnt[i] >= 0) 
        {
            ans = max(ans, i-1000*cnt[i]+dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}