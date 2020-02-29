#include<bits/stdc++.h>
using namespace std;

const int mod = 10000;

struct HP
{
    int len, v[10000];
    HP()
    {
        memset(v, 0, sizeof v);
        len = 0;
    }
    void print()
    {
        cout << v[len-1];
        for(int i = len-2; i >= 0; i--)
        {
            if(v[i] == 0) {cout << "0000"; continue;}
            for(int j = 10; j*v[i] < mod; j*=10)
                cout << "0";
            cout << v[i];
        }
        cout << endl;
    }

};

HP operator *(const HP& a, int b)
{
    HP c;
    int len = a.len, x = 0;
    c.len = len;
    for(int i = 0; i < len; i++)
    {
        c.v[i] = a.v[i]*b+x;
        x = c.v[i]/mod;
        c.v[i] %= mod;
    }
    while(x!=0)
    {
        c.v[c.len++] = x%mod;
        x /= mod;
    }
    return c;
}

HP operator +(const HP& a, int b)
{
    HP c = a;
    int x = b;
    for(int i = 0; i < c.len; i++)
    {
        c.v[i] = c.v[i] + x;
        x = c.v[i]/mod;
        c.v[i] %= mod;
    }
    if(x!=0) c.v[c.len++] = x;
    return c;
}

HP operator *(const HP& a, const HP b)
{
    HP c;
    int len = max(a.len, b.len) + min(a.len, b.len) - 1, x = 0;
    c.len = len;
    for(int i = 0; i < len; i++)
    {
        c.v[i] += x;
        x = 0;
        for(int j = i; j >= 0; j--)
        {
            c.v[i] += a.v[j]*b.v[i-j];
            x += c.v[i]/mod;
            c.v[i] %= mod;
        }
    }
    while(x!=0)
    {
        c.v[c.len++] = x%mod;
        x /= mod;
    }
    return c;
}

HP max(const HP& a, const HP& b)
{
    if(a.len < b.len) return b;
    else if(a.len > b.len) return a;
    else
    {
        for(int i = a.len-1; i >= 0; i--)
        {
            if(a.v[i] < b.v[i]) return b;
            else if(a.v[i] > b.v[i]) return a;
        }
        return a;
    }
}

int n, k;
string s;
HP dp[41][7];
int main()
{
    /* freopen("test.in", "r", stdin); */
    cin >> n >> k >> s;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0]  = (dp[i-1][0]*10+(s[i-1]-'0'));
        /* dp[i][0].print(); */
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            for(int l = 1; l < i; l++)
            {
                if(i-l<=j-1) continue;
                HP t;
                for(int k = i-l+1; k <= i; k++)
                    t = t*10 + (s[k-1]-'0');
                dp[i][j] = max(dp[i][j], dp[i-l][j-1]*t);
            }
            /* cout << "i, j " << i << " " << j << endl; */
            /* dp[i][j].print(); */
        }

    }
    dp[n][k].print();
    return 0;
}
