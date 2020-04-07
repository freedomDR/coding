#include<bits/stdc++.h>

using namespace std;

int dp[105][105], n, k, ans;

struct book
{
    int h, w;
}b[105];

bool cmp(book &b1, book &b2) {return b1.h<b2.h;}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i].h >> b[i].w;
    }
    sort(b+1, b+n+1, cmp);
    memset(dp, 0x3f, sizeof dp);
    memset(&ans, 0x3f, sizeof ans);
    memset(dp[0], 0, sizeof dp[0]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= min(i-1, k); j++)
        {
            for(int l = 0; l <= j; l++)
            {
                if(i-l-1 == 0) dp[i][j] = 0;
                else dp[i][j] = min(dp[i][j], dp[i-l-1][j-l]+abs(b[i].w-b[i-l-1].w));
            }
        }
    }
    for(int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[n-i][k-i]);
    }
    cout << ans << endl;
    return 0; 
}