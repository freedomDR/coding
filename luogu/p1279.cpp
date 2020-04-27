#include<bits/stdc++.h>

using namespace std;

//f[i][j] = max(abs(a1[i]-a2[j])+f[i-1][j-1], 2k+f[i-1][j-1], k+)
int dp[2005][2005], k;
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    cin >> k;
    int l1 = s1.size(), l2 = s2.size();
    sizeof(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= l2; i++) dp[0][i] = k*i;
    for(int i = 1; i <= l1; i++) dp[i][0] = k*i;
    s1 = "#"+s1;
    s2 = "#"+s2;
    dp[0][0] = 0;
    for(int i = 1; i <= l1; i++)
    {
        for(int j = 1; j <= l2; j++)
        {
            dp[i][j] = min(2*k, abs(s1[i]-s2[j]))+dp[i-1][j-1];
            dp[i][j] = min(dp[i][j], dp[i-1][j]+k);
            dp[i][j] = min(dp[i][j], dp[i][j-1]+k);
        }
    }
    cout << dp[l1][l2] << endl;
    return 0;
}