#include<bits/stdc++.h>

using namespace std;

long long n, W, cnt, dp[40005], f[40005], v[2005], w[2005], qidx[40005], qv[40005];
void slove1()
{
    // freopen("P1776_2.in", "r", stdin);
    cin >> n >> W;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        for(int j = 1; j <= c; j *= 2)
        {
            v[++cnt] = j*a;
            w[cnt] = j*b;
            c-=j;
        }
        if(c) v[++cnt] = c*a, w[cnt] = c*b;
        // int vv = a, ww = b;
        // while(c > 0)
        // {
        //     if(c&1) {v[++cnt] = vv; w[cnt] = ww;}
        //     vv *= 2;
        //     ww *= 2;
        //     c>>=1;
        // }
    }
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }
    cout << dp[W] << endl;
}

void slove2()
{
    // freopen("P1776_2.in", "r", stdin);
    cin >> n >> W;
    int temp = 0;
    for(int i = 1; i <= n; i++)
    {
        //dp[i][j] = max(dp[i-1][j-ww*k]+vv*k)(k<=cc)
        //dp[i][j] = max(dp[i-1][d+ww*k]+(s-k)*vv)
        int vv, ww, cc; cin >> vv >> ww >> cc;
        if(ww==0){temp+=vv*cc;continue;}
        int k = W/ww;
        cc = min(cc, k);
        for(int d = 0; d < ww; d++)
        {
            int l = 0, r = 0;
            k = (W-d)/ww;
            for(int j = 0; j <= k; j++)
            {
                while(l<r&&f[d+j*ww]-j*vv>=qv[r-1]) r--;
                qidx[r] = j;
                qv[r++] = f[d+j*ww]-j*vv;
                while(l<r&&qidx[l]<j-cc) l++;
                f[d+j*ww] = max(f[d+j*ww], qv[l]+j*vv);
            }
        }
    }
    cout << temp+f[W] << endl;
}

int main()
{
    // slove1();
    slove2();
    return 0;
}