#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[31][31], root[31][31];
ll scope[31], n;
void dfs(int l, int r)
{
    int p = root[l][r];
    cout << p << " ";
    if(l<=p-1) dfs(l, p-1);
    if(p+1<=r) dfs(p+1, r);
}
int main()
{
    /* freopen("test.in", "r", stdin); */
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> scope[i];
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = scope[i];
        root[i][i] = i;
    }
    for(int l = 1; l <= n; l++)
    {
        for(int i = 1; i+l <= n; i++)
        {
            for(int k = i; k <= i+l; k++)
            {
                ll t = scope[k]+(k==i?1:dp[i][k-1])*(k==i+l?1:dp[k+1][i+l]);
                if(dp[i][i+l] < t)
                {
                    dp[i][i+l] = t;
                    root[i][i+l] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    dfs(1, n);
    return 0;
}
