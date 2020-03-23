#include <bits/stdc++.h>

using namespace std;

int f[1<<18], g[1<<18], a[20], n, w;
int main()
{
    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof f);
    f[0] = 1;
    g[0] = w;
    for(int i = 0; i < (1<<18); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i&(1<<j)) continue;
            if(g[i]>=a[j]&&f[i|(1<<j)]>=f[i])
            {
                f[i|(1<<j)] = f[i];
                g[i|(1<<j)] = max(g[i|(1<<j)], g[i]-a[j]);
            }else if(g[i]<a[j]&&f[i|(1<<j)]>=f[i]+1)
            {
                f[i|(1<<j)] = f[i]+1;
                g[i|(1<<j)] = max(g[i|(1<<j)], w-a[j]);
            }
        }
    }
    cout << f[(1<<n)-1] << endl;
    return 0;
}