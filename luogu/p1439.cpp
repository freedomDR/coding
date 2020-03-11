#include<bits/stdc++.h>

using namespace std;

int n, dp[100100], len, a[100100], b[100100], p[100100];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(p[b[i]] > dp[len]) dp[++len] = p[b[i]];
        else 
            *lower_bound(dp+1, dp+len+1, p[b[i]]) = p[b[i]];
    }
    cout << len << endl;
    return 0;
}