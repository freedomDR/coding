#include<bits/stdc++.h>
using namespace std;
const int MAXN = 41;
int dp[MAXN][MAXN][MAXN][MAXN], b[5], a[351];
int main()
{
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        int tmp; cin >> tmp;
        b[tmp]++;
    }
    dp[0][0][0][0] = a[0];
    for(int i1 = 0; i1 <= b[1]; i1++)
        for(int i2 = 0; i2 <= b[2]; i2++)
            for(int i3 = 0; i3 <= b[3]; i3++)
                for(int i4 = 0; i4 <= b[4]; i4++)
                {
                    int tmp = i1+i2*2+i3*3+i4*4;
                    if(i1) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1-1][i2][i3][i4]+a[tmp]);
                    if(i2) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1][i2-1][i3][i4]+a[tmp]);
                    if(i3) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1][i2][i3-1][i4]+a[tmp]);
                    if(i4) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1][i2][i3][i4-1]+a[tmp]);
                }
    cout << dp[b[1]][b[2]][b[3]][b[4]] << endl;
    return 0;
}

