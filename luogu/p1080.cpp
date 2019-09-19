#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
struct Coin
{
    long long a, b;
    bool operator < (const Coin x) const
    {
        return a*b < x.a*x.b;
    }
}coin[1001];
int n, sums_len = 1, maxn_len = 1, ans_len = 1;
int sums[MAXN] = {0, 1}, maxn[MAXN] = {0, 1}, ans[MAXN];

void muti(long long x)
{
    int tmp = 0;
    for(int i = 1; i <= sums_len; i++)
    {
        sums[i] *= x;
    }
    for(int i = 1; i <= sums_len; i++)
    {
        tmp += sums[i];
        sums[i] = tmp%10;
        tmp /= 10;
    }
    while(tmp != 0)
    {
        sums_len++;
        sums[sums_len] = tmp%10;
        tmp /= 10;
    }
}

void divide(long long x)
{
    memset(ans, 0, sizeof(ans));
    ans_len = sums_len;
    int tmp = 0;
    for(int i = ans_len; i >= 1; i--)
    {
        tmp *= 10;
        tmp += sums[i];
        if(tmp >= x)
        {
            ans[i] = tmp/x;
            tmp %= x;
        }
    }
    while(ans[ans_len] == 0)
    {
        if(ans_len == 1) break;
        ans_len--;
    }
}

void max()
{
    if(ans_len > maxn_len)
    {
        for(int i = 1; i <= ans_len; i++) maxn[i] = ans[i];
        maxn_len = ans_len;
    }   
    else if(ans_len == maxn_len)
    {
        for(int i = ans_len; i >= 1; i--)
        {
            if(ans[i] > maxn[i])
            {
                for(int j = 1; j <= ans_len; j++)
                    maxn[j] = ans[j];
                break;
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> coin[0].a >> coin[0].b;
    for(int i = 1; i <= n; i++) cin >> coin[i].a >> coin[i].b;
    sort(coin+1, coin+n+1);
    for(int i = 1; i <= n; i++)
    {
        muti(coin[i-1].a);
        divide(coin[i].b);
        max();
    }
    for(int i = maxn_len; i >= 1; i--)
        cout << maxn[i];
    return 0;
}
