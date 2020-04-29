#include<bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int dp[maxn][maxn][2], n, g[maxn][maxn], pos;
void print(int x, int y, int pre)
{
    if(x==1&&y==1)
    {
        cout << (pre?'D':'R');
        return;
    }
    if(x==1) print(x,y-1, 0);
    else if(y==1) print(x-1, y, 1);
    else if(dp[x-1][y][pos]<dp[x][y-1][pos]) print(x-1, y, 1);
    else print(x, y-1, 0);
    if(pre >= 0) 
        cout << (pre?'D':'R');
}
int main()
{
    bool have_zero = false;
    int x, y;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if(g[i][j]==0) {have_zero = true; x = i; y = j;}
        }
    }
    for(int i = 1; i <= n; i++)
        dp[0][i][0] = dp[0][i][1] = dp[i][0][0] = dp[i][0][1] = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int cnt2 = 0, cnt5 = 0, tmp = g[i][j];
            if(g[i][j]==0) cnt2 = cnt5 = 1;
            else
            {
                while(tmp%2==0) {cnt2++;tmp/=2;}
                tmp = g[i][j];
                while(tmp%5==0) {cnt5++;tmp/=5;}
            }
            if(i==1 && j==1)
            {
                dp[i][j][0] = cnt2;
                dp[i][j][1] = cnt5;
            }else
            {
                dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0])+cnt2;
                dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1])+cnt5;
            }
        }
    }
    int ans = min(dp[n][n][0], dp[n][n][1]);
    if(have_zero&&ans>1)
    {
        cout << "1" << endl;
        for(int i = 1; i < x; i++)
            cout << "D";
        for(int i = 1; i < n; i++)
            cout << "R";
        for(int i = x; i < n; i++)
            cout << "D";
    }else
    {
        cout << ans << endl;
        if(ans==dp[n][n][1]) pos = 1;
        print(n, n, -1);
    }
    
    return 0;
}