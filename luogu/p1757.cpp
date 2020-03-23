#include<bits/stdc++.h>

using namespace std;

int dp[1010], n, m, num;
int main()
{
    vector<vector<pair<int, int>>> p(110, vector<pair<int, int>>());
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        int a, b ,c;
        cin >> a >> b >> c;
        num = max(num, c);
        p[c].push_back(make_pair(a, b));
    }
    for(int i = 1; i <= num; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k < p[i].size(); k++)
            {
                if(j>=p[i][k].first)
                    dp[j] = max(dp[j], dp[j-p[i][k].first]+p[i][k].second);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}