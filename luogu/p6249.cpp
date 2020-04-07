#include<bits/stdc++.h>

using namespace std;
long long n, ans;
long long dp[202][202][501][2];
struct T
{
    int x, v, t;
}arr[202];
int main()
{
    // freopen("P6249_2.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &arr[i].x, &arr[i].v, &arr[i].t);
    }
    arr[n].x = 0; arr[n].v = 0; arr[n].t = -1;
    n++;
    sort(arr, arr+n, [](auto &a1, auto &a2){return a1.x<a2.x;});
    int st = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].t == -1) st = i;
    }
    memset(dp, -0x7f, sizeof(dp));
    memset(dp[st][st], 0, sizeof(dp[st][st]));
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0, j = i+len-1; j < n; i++, j++)
        {
            int need_t1 = arr[i+1].x - arr[i].x;
            int need_t2 = arr[j].x - arr[i].x;
            int need_t3 = arr[j].x - arr[i].x;
            int need_t4 = arr[j].x - arr[j-1].x;
            for(int t = 0; t <= 500; t++)
            {
                int add = arr[i].t>=t?arr[i].v:0;
                if(t>=need_t1) dp[i][j][t][0] = max(dp[i][j][t-1][0], dp[i+1][j][t-need_t1][0]+add);
                if(t>=need_t2) dp[i][j][t][0] = max(dp[i][j][t][0], dp[i+1][j][t-need_t2][1]+add);
                add = arr[j].t>=t?arr[j].v:0;
                if(t>=need_t3) dp[i][j][t][1] = max(dp[i][j][t-1][1], dp[i][j-1][t-need_t3][0]+add);
                if(t>=need_t4) dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j-1][t-need_t4][1]+add);
            }
            ans = max(ans, dp[i][j][500][1]);
            ans = max(ans, dp[i][j][500][0]);
        }
    }
    cout << ans << endl;
    return 0;
}