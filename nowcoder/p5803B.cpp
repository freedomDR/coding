#include<bits/stdc++.h>

using namespace std;
long long a[20], b[20], c[20], d[20], n;

long long dfs(int p, long long money, long long magic)
{
    if(p == n+1)
    {
        return money*magic;
    }
    long long ret1 = dfs(p+1, money+a[p], magic-b[p]>0?magic-b[p]:0);
    long long ret2 = dfs(p+1, money-d[p]>0?money-d[p]:0, magic+c[p]);
    return max(ret1, ret2);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    long long ret = dfs(1, 0, 0);        
    cout << ret << endl;
    return 0;
}