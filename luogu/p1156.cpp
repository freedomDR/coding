#include<bits/stdc++.h>

using namespace std;

int d, g;

struct Rubbish
{
    int t, h, f;

    bool operator < (const Rubbish &r)
    {
        return t < r.t;
    }
}rub[1005];

int dp[1005][150];

int main()
{
    cin >> d >> g;
    for(int i = 1; i <= g; i++)
    {
        cin >> rub[i].t >> rub[i].f >> rub[i].h;
    }
    sort(rub+1, rub+g+1);
    int livetime = 0;
    for(auto &row:dp)
        for(auto &v:row)
            v = -1;
    dp[0][0] = 10;
    for(int i = 1; i <= g; i++)
    {
        for(int j = 0; j <= d; j++)
        {
            if(dp[i-1][j] < rub[i].t-rub[i-1].t) continue;
            if(j+rub[i].h>=d) 
            {
                cout << rub[i].t << endl;
                return 0;
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]+rub[i].f-(rub[i].t-rub[i-1].t));
            dp[i][j+rub[i].h] = max(dp[i][j+rub[i].h], dp[i-1][j]-(rub[i].t-rub[i-1].t));
        }
        livetime = max(livetime, dp[i][0]+rub[i].t);
    }
    cout << livetime << endl;
    return 0;
}
