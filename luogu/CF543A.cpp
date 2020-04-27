#include<bits/stdc++.h>

using namespace std;

//f[i][j][k] = f[i-1][j-jj][k-jj*bug[i]]
int n, m, b, mod, f[505][505], a[505];
int main()
{
    cin >> n >> m >> b >> mod;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = a[i]; k <= b; k++)
                f[j][k] = (f[j][k]+f[j-1][k-a[i]])%mod;
    int ans = 0;
    for(int i = 0; i <= b; i++) ans = (ans+f[m][i])%mod;
    cout << ans << endl;
    return 0;
}