#include<bits/stdc++.h>

using namespace std;

int a[5005], dp[5005], c[5005], cnt, len, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        c[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[i] < a[j]) 
            {
                if(dp[i] == dp[j]+1) c[i]+=c[j];
                else if(dp[i] < dp[j]+1) 
                {
                    dp[i] = dp[j]+1;
                    c[i] = c[j];
                }
            }
            if(a[i] == a[j])
                dp[j] = c[j] = 0;
        }   
        len = max(len, dp[i]);
    }
    for(int i = 1; i <= n; i++)
        if(dp[i] == len) cnt+=c[i];
    cout << len << " " << cnt << endl;
    return 0;
}
