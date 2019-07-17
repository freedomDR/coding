#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+100;
int f[2][N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= 2*n; i++)
    {
        int a;
        cin>>a;
        if(!f[0][a]) f[0][a] = i;
        else f[1][a] = i;
    }
    long long ans = 0;
    f[0][0]=f[1][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        ans += abs(f[0][i]-f[0][i-1])+abs(f[1][i]-f[1][i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
