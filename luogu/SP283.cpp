#include<bits/stdc++.h>

using namespace std;

const int maxn = 4000;
int dp1[2][maxn][2], dp2[2][maxn][2], n, b, v[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> b;
        for(int i = 1; i <= n; i++) cin >> v[i];
        memset(dp1, -0x3f, sizeof dp1);
        memset(dp2, -0x3f, sizeof dp2);
        dp1[1][1][1] = dp1[1][0][0] = 0;
        dp2[1][1][1] = v[1];
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j <= min(i, b); j++)
            {
                dp1[i%2][j][0] = max(dp1[(i-1)%2][j][0], dp1[(i-1)%2][j][1]);
                if(j>=1)dp1[i%2][j][1] = max(dp1[(i-1)%2][j-1][0], dp1[(i-1)%2][j-1][1]+v[i]);
                dp2[i%2][j][0] = max(dp2[(i-1)%2][j][0], dp2[(i-1)%2][j][1]);
                if(j>=1)dp2[i%2][j][1] = max(dp2[(i-1)%2][j-1][0], dp2[(i-1)%2][j-1][1]+v[i]);
            }
        }
        cout << max(dp2[n%2][b][1], max(dp1[n%2][b][0], dp1[n%2][b][1])) << endl;
    }
    return 0;
}