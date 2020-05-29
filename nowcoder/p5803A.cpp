#include<bits/stdc++.h>

using namespace std;

long long dp[35][160];
long long gcd(long long a, long long b)
{
    return (b==0?a:gcd(b, a%b));
}
int main()
{
    int n; 
    cin >> n;
    dp[0][0] = 1;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= 120; j++)
        {
            for(int k = 1; k <= 4; k++)
                dp[i][j+k] += dp[i-1][j];
        }
    }
    long long a = 0, b = pow(4, n);
    for(int i = 3*n; i < 160; i++)
    {
        a += dp[n][i];
    }
    long long p = gcd(a, b);
    cout << a/p << "/" << b/p << endl;
    return 0;
}