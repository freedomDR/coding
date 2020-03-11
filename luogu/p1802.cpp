#include<bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, x, lose[N], win[N], use[N];
long long dp[N];

int main()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = x; j >= 0; j--)
        {
            if(j>=use[i])
                dp[j] = max(dp[j]+lose[i], dp[j-use[i]]+win[i]);
            else
                dp[j] = dp[j]+lose[i];
        }
    }
    cout << dp[x]*5 << endl;
    return 0;
}