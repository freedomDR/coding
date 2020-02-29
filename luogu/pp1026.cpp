#include<bits/stdc++.h>

using namespace std;

int p, k, s;
string ss, dic[7];
int dp[201][21], d[201];
int main()
{
    cin >> p >> k;
    for(int i = 0; i < p; i++) 
    {
        string temp;
        cin >> temp; ss+=temp;
    }
    cin >> s;
    for(int i = 0; i < s; i++)
        cin >> dic[i];
    for(int i = 0; i < (int)ss.size(); i++)
    {
        int r = 205;
        for(int j = 0; j < s; j++)
        {
            if(ss.substr(i,dic[j].size()) == dic[j])
            {
                r = min(r, (int)dic[j].size()+i-1);
            }
        }
        d[i] = r;
    }
    for(int i = 0; i < (int)ss.size(); i++)
    {
        for(int j = 1; j <= k; j++)
        {
            int sums = 0;
            for(int l = i-1; l+1 >= j-1; l--) // 太坑了 坑死了
            {
                if(d[l+1] <= i) sums++;
                if(l != -1) 
                    dp[i][j] = max(dp[i][j], dp[l][j-1]+sums);
                else 
                    dp[i][j] = sums;
            }
        }
    }
    cout << dp[ss.size()-1][k] << endl;
    return 0;
}
