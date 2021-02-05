#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[4][4];
const int maxn = 3050;
long long dp[maxn][maxn][3];
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif 
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> d[i][j];
    int a, b; cin >> a >> b;
    map<char, int> mp;
    mp['A'] = 0;
    mp['T'] = 1;
    mp['G'] = 2;
    mp['C'] = 3;
    s1 = "-"+s1;
    s2 = "-"+s2;
    //memset(dp, 0, sizeof(dp));
    int n = s1.size(), m = s2.size();
    for(int i = 1; i < max(n, m); ++i)
    {
        dp[0][i][0] = dp[i][0][0] = dp[0][i][2] = dp[i][0][1] = -(1LL<<60);
        dp[0][i][1] = dp[i][0][2] = -a-b*(i-1);
    }
    dp[0][0][1] = dp[0][0][2] = -(1LL<<60);
    for(int i = 1; i < s1.size(); ++i)
    {
        for(int j = 1; j < s2.size(); ++j)
        {
            dp[i][j][0] = *max_element(dp[i-1][j-1], dp[i-1][j-1]+3)+d[mp[s1[i]]][mp[s2[j]]];
            dp[i][j][1] = max(dp[i][j-1][0]-a, max(dp[i][j-1][1]-b, dp[i][j-1][2]-a));
            dp[i][j][2] = max(dp[i-1][j][0]-a, max(dp[i-1][j][1]-a, dp[i-1][j][2]-b));
        }
    }
    cout << *max_element(dp[n-1][m-1], dp[n-1][m-1]+3) << endl;
    return 0;
}