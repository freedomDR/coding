#include <bits/stdc++.h>

using namespace std;

int m, n, ans;
int f[25], dp[2005];
bool used[25];

void calc()
{
    memset(dp, 0, sizeof(dp));
    int maxv = 0, cnt = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        if(used[i]) continue;
        for(int j = maxv; j >= 0; j--)
            if(!dp[j+f[i]]&&dp[j])
            {
                cnt++;
                dp[j+f[i]] = 1;
            }
        maxv+=f[i];
    }
    ans = max(ans, cnt);
}

void dfs(int pos, int del)
{
    if(del > m) return;
    if(pos == n) {if(del == m) calc();return;}
    dfs(pos+1, del);
    used[pos] = true;
    dfs(pos+1, del+1);
    used[pos] = false;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> f[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
