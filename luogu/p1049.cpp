#include<bits/stdc++.h>

using namespace std;

int dp[20010], n, v, a[35];
int main()
{   
    cin >> v >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = v; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
        }
    }
    cout << v-dp[v] << endl;
    return 0;
}