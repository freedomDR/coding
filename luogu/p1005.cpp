#include<bits/stdc++.h>

using namespace std;

const int mod = 10000;

struct HP
{
    int a[1000], len;
    HP()
    {
        memset(a, 0, sizeof a);
        len = 0;
    }

    void print()
    {
        cout << a[len-1];
        for(int i = len-2; i >= 0; i--)
        {
            for(int j = 10; j*a[i]<mod; j*=10)
                cout << "0";
            cout << a[i];
        }
        cout << endl;
    }
};
HP dp[85][85], two[85];

int g[85][85], n, m;

HP operator +(const HP& a, const HP& b)
{
    HP c;
    int len = max(a.len, b.len), x = 0;
    c.len = len;
    for(int i = 0; i < len; i++)
    {
        c.a[i] = a.a[i]+b.a[i] + x;
        x = c.a[i]/mod;
        c.a[i] %= mod;
    }
    while(x!=0)
    {
        c.a[c.len++] += x%mod;
        x/= mod;
    }
    return c;
}
HP operator *(const HP& a, int b)
{
    HP c;
    int len = a.len, x = 0;
    c.len = len;
    for(int i = 0; i < len; i++)
    {
        c.a[i] = a.a[i]*b + x;
        x = c.a[i]/mod;
        c.a[i] %= mod;
    }
    while(x!=0)
    {
        c.a[c.len++] = x%mod;
        x /= mod;
    }
    return c;
}

HP max(const HP& a, const HP& b)
{
    if(a.len > b.len) return a;
    else if(a.len < b.len) return b;
    else
    {
        for(int i = a.len-1; i >= 0; i--)
        {
            if(a.a[i] > b.a[i]) return a;
            else if(a.a[i] < b.a[i]) return b;
        }
        return a;
    }
} 

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    two[0].a[0] = 1;
    two[0].len = 1;
    for(int i = 1; i <= m; i++)
    {
        two[i] = two[i-1]*2;
    }
    HP ans;
    for(int k = 1; k <= n; k++)
    {
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= m; i++)
        {
            for(int j = m; j >= 1 && j >= i; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+two[m-(j-i+1)]*g[k][i-1]);
                dp[i][j] = max(dp[i][j], dp[i][j+1]+two[m-(j-i+1)]*g[k][j+1]);
            }
        }
        HP temp;
        for(int i = 1; i <= m; i++)
        {
            temp = max(temp, dp[i][i]+two[m]*g[k][i]);
        }
        ans = ans + temp;
    }
    ans.print();
    return 0;
}

