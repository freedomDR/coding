#include<bits/stdc++.h>

using namespace std;

int dp[200005];
int main()
{
    // freopen("P1470_5.in", "r", stdin);
    string tmp;
    set<string> s;
    int maxLen = 0;
    while(1)
    {
        cin >> tmp;
        if(tmp == ".") break;
        s.insert(tmp);
        maxLen = max(maxLen, (int)tmp.size());
    }
    string ori = " ";
    while(cin >> tmp)
        ori += tmp;
    int ans = 0;
    dp[0] = 1;
    for(int i = 1; i < ori.size(); i++)
    {
        for(int j = 1; j <= maxLen && j <= i; j++)
        {
            tmp = ori.substr(i-j+1, j);
            if(s.find(tmp) != s.end() && dp[i-j]==1)
            {
                ans = i;
                dp[i] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}