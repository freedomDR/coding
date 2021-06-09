#include<iostream>
#include<string.h>
#include<cstdio>

using namespace std;

const int N = 50050;
int a[N], suf[N], fis[N];

int main()
{
    #ifdef LOCAL
        freopen("/Users/dongrui05/code/coding/luogu/p3131.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    memset(fis, 0x7f, sizeof(fis));
    for(int i = 1; i <= n; i++)
    {
        suf[i] = (suf[i-1]+a[i])%7;
        ans = max(ans, i-fis[suf[i]]);
        fis[suf[i]] = min(fis[suf[i]], i);
    }
    cout << ans << endl;
    return 0;
}