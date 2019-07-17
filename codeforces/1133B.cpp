#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> d(k);
    for(int i = 0; i < n; i++)
    {
        int tmp;cin>>tmp;
        d[tmp%k]++;
    }
    int ans = 0;
    for(int i = 0; i <= k/2; i++)
    {
        if(i == 0 || k == i*2) ans += d[i]-d[i]%2;
        else ans += min(d[i], d[k-i])*2;
    }
    cout<<ans<<endl;
    return 0;
}
