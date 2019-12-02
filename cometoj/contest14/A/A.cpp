#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,r;
    cin >> n >> a >> b >> r;
    int ans = 0;
    long long limit = 1LL*r*r;
    while(n--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        long long tmp = 1LL*(v1-a)*(v1-a)+1LL*(v2-b)*(v2-b);
        if(tmp <= limit) ans++;
    }
    cout << ans << endl;
    return 0;
}
