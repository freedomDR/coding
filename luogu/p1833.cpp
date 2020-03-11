#include<bits/stdc++.h>

using namespace std;

int dp[1001], a0, b0, a1, b1, n, cnt, a[1001], v[1001], htime;

void calc(int t, int c, int p)
{
    int base = 1;
    while(p)
    {
        a[++cnt] = base*t;
        v[cnt] = base*c;
        p-=base;
        base *= 2;
        if(p<base)
        {
            a[++cnt] = p*t;
            v[cnt] = p*c;
            break;
        }
    }
}

// 多重背包二进制优化
void solve_1()
{
    scanf("%d:%d %d:%d %d", &a0, &b0, &a1, &b1, &n);   
    htime = (a1-a0)*60+(b1-b0); 
    for(int i = 1; i <= n; i++)
    {
        int t, c, p;
        cin >> t >> c >> p;
        if(p == 0)
        {
            for(int j = 0; j+t <= htime; j++)
                dp[j+t] = max(dp[j+t], dp[j]+c);
        }
        else
        {
            cnt = 0;
            calc(t, c, p);
            for(int j = 1; j <= cnt; j++)
            {
                for(int jj = htime; jj >= a[j]; jj--)
                    dp[jj] = max(dp[jj], dp[jj-a[j]]+v[j]);
            } 
        }
    }
    cout << dp[htime] << endl;
}
int q1[1001], q2[1001];
//单调队列优化
void slove_2()
{
    scanf("%d:%d %d:%d %d", &a0, &b0, &a1, &b1, &n);   
    htime = (a1-a0)*60+(b1-b0); 
    for(int i = 1; i <= n; i++)
    {
        int t, c, p;
        cin >> t >> c >> p;
        if(p == 0)
        {
            for(int j = 0; j+t <= htime; j++)
                dp[j+t] = max(dp[j+t], dp[j]+c);
        }
        else
        {
            //dp[d+k*t] = max(dp[d+kk*t]+(k-kk)*c) = max(dp[d+kk*t]-kk*c)+k*c (0<=kk<=p)
            for(int d = 0; d < t; d++)
            {
                int l = 1, r = 0;
                int maxk = (htime-d)/t;
                for(int k = 0; k <= maxk; k++)
                {
                    int &x = dp[d+k*t];
                    while(l<=r&&q2[r]<=x-c*k) r--;
                    q1[++r] = k; q2[r] = x-c*k;
                    while(l<=r&&q1[l]<k-p) l++;
                    if(l<=r)
                        x = max(x, q2[l]+c*k);
                }
            }
        }
    }
    cout << dp[htime] << endl;
}
int main()
{
    slove_2();
    return 0;
}