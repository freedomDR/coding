#include<bits/stdc++.h>

using namespace std;

int n, s, dp[5050], c[5050], t[5050], q[5050];

//dp[i] = dp[j] + (c[i]-c[j])*t[i] + s*(c[n]-c[j])
//dp[j] = (s+t[i])*c[j] + dp[i]-c[i]*t[i]-s*c[n];
int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        int tv, cv;
        cin >> tv >> cv;
        c[i] = c[i-1]+cv;
        t[i] = t[i-1]+tv;
    }
    memset(dp, 0x3f, sizeof(dp));
    int l, r;
    l = r = 1;
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        while(l<r&&dp[q[l+1]]-dp[q[l]]<=(s+t[i])*(c[q[l+1]]-c[q[l]])) l++;   
        dp[i] = dp[q[l]]+(c[i]-c[q[l]])*t[i]+s*(c[n]-c[q[l]]);
        while(l<r&&(dp[i]-dp[q[r]])*(c[q[r]]-c[q[r-1]])<=(dp[q[r]]-dp[q[r-1]])*(c[i]-c[q[r]])) r--;
        q[++r] = i;
    }
    cout << dp[n] << endl;
    return 0;
}