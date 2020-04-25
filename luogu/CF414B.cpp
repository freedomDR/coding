#include<bits/stdc++.h>

using namespace std;

//f[i][j] = sums(f[i-1][kk]) (j%kk==0)
const int mod = 1e9+7;
int n, k;
long long f[2005];
int main()
{
    cin >> n >> k;
    fill(f, f+2005, 1);
    for(int i = 2; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int kk = j+j; kk <= n ; kk+=j)
                f[j] = (f[j]+f[kk])%mod;
        }
    }
    long long sums = 0;
    for(int i = 1; i <= n; i++) sums += f[i], sums %= mod;
    cout << sums << endl;
    // cout << accumulate(f+1, f+1+n, 0) << endl;
    return 0;
}