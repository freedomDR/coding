#include<bits/stdc++.h>

using namespace std;

//dp[n][k][p][v]
int dp[10][100100], n, p, k, s[100100][10], a[100100];
int main()
{
    cin >> n >> p >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p; j++)
            cin >> s[i][j];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
    }
    return 0;
}