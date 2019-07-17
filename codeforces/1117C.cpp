#include <bits/stdc++.h>

using namespace std;
const int max_n = 2e5+5;
int ud[max_n], lr[max_n];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int x1, y1, x2, y2, n;
    string s;
    cin>>x1>>y1>>x2>>y2>>n>>s;
    for(int i = 1; i <= n; i++)
    {
        ud[i] = ud[i-1];lr[i] = lr[i-1];
        if(s[i-1] == 'U') ud[i]++;
        else if(s[i-1] == 'D') ud[i]--;
        else if(s[i-1] == 'L') lr[i]--;
        else lr[i]++;
    }
    auto can = [&](long long step)
    {
        long long sud = ud[n]*(step/n)+ud[step%n];
        long long slr = lr[n]*(step/n)+lr[step%n];
        return (abs(x2-x1-slr)+abs(y2-y1-sud)<=step);
    };
    long long ans = (1LL<<48) - 1;
    if(!can(ans)) {cout<<"-1"<<endl; return 0;}
    for(int i = 47; i >= 0; i--)
        if(can(ans-(1LL<<i))) ans -= 1LL<<i;
    cout<<ans<<endl;
    return 0;
}
