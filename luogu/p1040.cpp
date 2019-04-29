#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<unsigned int>>& root, int l, int r)
{
    if(l > r) return;
    cout<<root[l][r]<<" ";
    print(root, l, root[l][r]-1);
    print(root, root[l][r]+1, r);
}


/*
 * 区间dp dp[i][j] i节点到j节点的最大值
 */
void dp_slove()
{
    int n;cin>>n;
    vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(n+1, 0)), root(n+1, vector<unsigned int>(n+1, 0));
    for(int i = 0; i < n+1; ++i)
        for(int j = 0; j < n+1; ++j)
            dp[i][j] = 0;
    for(int i = 1; i <= n; i++) {dp[i][i-1] = 1; root[i][i] = i;}
    for(int i = 1; i <= n; i++)
    {
        unsigned int v; cin>>v;
        dp[i][i] = v;
    }
    for(int len = 1; len < n; ++len)
    {
        for(int i = 1; i+len <= n; ++i)
        {
            int j = i+len;
            for(int k = i; k < j; k++)
            {
                if(dp[i][j] < dp[i][k-1]*dp[k+1][j]+dp[k][k])
                {
                    dp[i][j] = dp[i][k-1]*dp[k+1][j]+dp[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    print(root, 1, n);
}

int get(int l, int r, vector<vector<unsigned int>>& dp, vector<vector<unsigned int>>& root)
{
    if(l > r) return 1;
    if(dp[l][r]) return dp[l][r];
    for(int i = l; i <= r; i++)
    {
        unsigned int v = get(l, i-1, dp, root)*get(i+1, r, dp, root)+dp[i][i];
        if(v > dp[l][r])
        {
            dp[l][r] = v;
            root[l][r] = i;
        }
    }
    /* cout<<" l = "<<l<<" r = "<<r<<" dp[l][r] = "<<dp[l][r]<<endl; */
    return dp[l][r];
}

/*
 * 记忆化搜索
 */
void search()
{
    int n; cin>>n;
    vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(n+1, 0)), root(n+1, vector<unsigned int>(n+1, 0));
    for(int i = 1; i <= n; i++)
    {
        unsigned int v; cin>>v;
        dp[i][i] = v;
        root[i][i] = i;
    }
    cout<<get(1, n, dp, root)<<endl;
    print(root, 1, n);
}

int main()
{
    /* dp_slove(); */
    search();
    return 0;
}
