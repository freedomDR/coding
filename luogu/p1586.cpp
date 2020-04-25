#include<bits/stdc++.h>

using namespace std;

const int maxn = 40000;
long long dp[maxn][5]; 
void pre()
{
    dp[0][0] = 1;
    for(int i = 1; i*i < maxn; i++)
        for(int j = i*i; j < maxn; j++)
            for(int l = 1; l <= 4; l++)
                dp[j][l] += dp[j-i*i][l-1];
}
int main()
{
    pre();
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << accumulate(dp[n]+1, dp[n]+5, 0) << endl;
    }
    return 0;
}