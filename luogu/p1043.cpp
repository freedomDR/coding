#include<bits/stdc++.h>
using namespace std;

int n, m, a[110], dp1[110][110][10], prefix[110], dp2[110][110][10];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i = 1; i <= 2*n; i++)
    {
        prefix[i] = prefix[i-1]+a[i];
    }
    memset(dp2, 0x3f3f3f3f, sizeof dp2);
    for(int i = 1; i <= 2*n; i++)
    {
        for(int j = 1; j <= 2*n; j++)
        {
            dp1[i][j][1] = dp2[i][j][1] = ((prefix[j]-prefix[i-1])%10+10)%10;
        }
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1, j = i+len-1; j <= 2*n; i++, j++)
        {
            for(int mm = 2; mm <= m; mm++)
            {
                for(int k = i+mm-1; k < j; k++)
                {
                    dp1[i][j][mm] = max(dp1[i][j][mm], dp1[i][k][mm-1]*(((prefix[j]-prefix[k])%10+10)%10));
                    dp2[i][j][mm] = min(dp2[i][j][mm], dp2[i][k][mm-1]*(((prefix[j]-prefix[k])%10+10)%10));
                }
            }
        }
    }
    int ans1 = 0, ans2 = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        ans1 = max(ans1, dp1[i][i+n-1][m]);
        ans2 = min(ans2, dp2[i][i+n-1][m]);
    }
    cout << ans2 << endl;
    cout << ans1 << endl;
    return 0;
}
