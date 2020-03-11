#include<bits/stdc++.h>

using namespace std;

int dp[2020][2020];
int main()
{
    string a, b;
    cin >> a >> b;
    int alen = a.size(), blen = b.size();
    for(int i = 1; i <= alen; i++) dp[i][0] = i;
    for(int i = 1; i <= blen; i++) dp[0][i] = i;
    for(int i = 1; i <= alen; i++)
    {
        for(int j = 1; j <= blen; j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else
            {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
            
        }
    }
    cout << dp[alen][blen] << endl;
    return 0;
}