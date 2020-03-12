#include<bits/stdc++.h>

using namespace std;

int n, dp1[222][222], dp2[222][222], a[222], prefix[222];

int main()
{
    cin >> n; 
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i = 1; i <= 2*n; i++)
        prefix[i] = prefix[i-1]+a[i];
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1, j = i+len-1; j <= 2*n; i++, j++)
        {
            dp2[i][j] = 0x7f7f7f7f;
            for(int k = i; k < j; k++)
            {
                dp1[i][j] = max(dp1[i][j], dp1[i][k]+dp1[k+1][j]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k]+dp2[k+1][j]);
            }
            dp1[i][j] += prefix[j]-prefix[i-1];
            dp2[i][j] += prefix[j]-prefix[i-1];
        }
    }
    int ans1 = 0, ans2 = 0x7f7f7f7f;
    for(int i = 1; i+n-1 <= 2*n; i++)
    {
        ans1 = max(dp1[i][i+n-1], ans1);
        ans2 = min(dp2[i][i+n-1], ans2);
    }
    cout << ans2 << endl << ans1 << endl;
    return 0;
}