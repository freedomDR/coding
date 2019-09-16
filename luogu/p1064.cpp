#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> item(m+1, vector<pair<int, int>>());
    vector<vector<int>> dp(n+1, vector<int>(2));//dp[k][0] dp[k][1]
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0)
        {
            if(!item[i+1].empty()) item[i+1].emplace(item[i+1].begin(),a, b);
            else item[i+1].push_back({a, b});
        }
        else
        {
            item[c].push_back({a, b});
        }
    }
    for(int i = 1; i < m+1; i++) 
    {
        if(item[i].empty()) continue; //不是分组
        int main_a = item[i][0].first, main_b = item[i][0].second;
        if(item[i].size() == 1) //没有附件 完全背包
        {
            for(int v = n; v >= main_a; v--)
                dp[v][0] = max(dp[v][0], dp[v-main_a][0]+main_a*main_b);
        }
        else
        {
            for(int v = n; v >= main_a; v--)
                dp[v][1] = dp[v-main_a][0]+main_a*main_b;
            for(int l = 1; l < item[i].size(); l++)
            {
                int al   = item[i][l].first, bl = item[i][l].second;
                for(int v = n; v >= main_a+al; v--)
                    dp[v][1] = max(dp[v][1], dp[v-al][1]+al*bl);
            }
            for(int v = n; v >= main_a; v--) dp[v][0] = max(dp[v][1], dp[v][0]);
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
