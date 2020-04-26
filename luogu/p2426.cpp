#include<bits/stdc++.h>

using namespace std;
const int maxn = 1005;
long long dp[maxn], n, a[maxn];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1]+a[i];
        for(int j = i-1; j >= 1; j--)
            dp[i] = max(1ll*dp[i], dp[j-1]+abs(a[i]-a[j])*(i-j+1));
    }
    cout << dp[n] << endl;
    return 0;
}