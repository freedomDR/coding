class Solution {
public:
    bool match(char* s, char* p)
    {
    int s_len = strlen(s), p_len = strlen(p);
    vector<vector<bool>> dp(s_len+1, vector<bool>(p_len+1, false));
    dp[0][0] = true;
    for(int i = 0; i <= s_len; i++)
    {
        for(int j = 1; j <= p_len; j++)
        {
            if(p[j-1] == '*')
                dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            else 
                dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
        }
    }
    return dp[s_len][p_len];  
    }
};
