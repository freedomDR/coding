#include<iostream>

using namespace std;

const int maxn = 5050;
int a[maxn], dp[maxn][maxn], ans[maxn][maxn];
int q, l, r, m;

int main()
{
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
        dp[i][i] = a[i];
        ans[i][i] = a[i];
    }
    for(int len = 2; len <= m; len++)
    {
        for(int i = 1, j = i+len-1; j <= m; j++, i++)
        {
            dp[i][j] = dp[i][j-1] ^ dp[i+1][j];
            ans[i][j] = max(dp[i][j], max(ans[i][j-1], ans[i+1][j]));
        }
    }
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << ans[l][r] << endl;
    }
    return 0;
}