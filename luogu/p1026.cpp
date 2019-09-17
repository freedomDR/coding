#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p, K; cin >> p >> K;
    string s = "";
    while(p--)
    {
        string tmp = ""; cin >> tmp;
        s += tmp;
    }
    int p_cnt = 0;
    cin >> p_cnt;
    vector<string> pattern(p_cnt);
    for(int i = 0; i < p_cnt; i++) cin >> pattern[i];
    vector<vector<int>> sums(s.size(), vector<int>(s.size()));
    vector<vector<int>> dp(s.size(), vector<int>(K));
    for(int i = (int)s.size()-1; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            sums[j][i] = (j+1>=(int)s.size() ? 0: sums[j+1][i]);
            string tmp = s.substr(j, i-j+1);
            bool find = false;
            for(int k = 0; k < p_cnt && !find; k++)
            {
                if(tmp.find(pattern[k]) == 0) find = true;
            }
            if(find) sums[j][i]++;
        }
    }
    for(int i = 1; i < K; i++) dp[i-1][i] = (i == 1 ? 0 : dp[i-2][i-1]) + sums[i-1][i-1];
    for(int i = 0; i < (int)s.size(); i++) dp[i][0] = sums[0][i];
    for(int i = 0; i < (int)s.size(); i++) 
    {
        for(int j = 0; j < K; j++)
        {
            for(int l = j; l < i; l++)
                dp[i][j] = max(dp[i][j], (j == 0 ? 0:dp[l][j-1])+sums[l+1][i]);
        }
    }
    cout << dp[s.size()-1][K-1] << endl;
    return 0;
}
