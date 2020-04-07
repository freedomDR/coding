#include<bits/stdc++.h>

using namespace std;

int n, m, a[2505], dp[2505];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i]==2)a[i]=-1;
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for(int j = i; j > 0; j--)
        {
            tmp += a[j];
            if(abs(tmp)<=m||(abs(tmp) == i-j+1)) dp[i] = min(dp[i], dp[j-1]+1);
        }
    }
    cout << dp[n] << endl;
    return 0; 
}