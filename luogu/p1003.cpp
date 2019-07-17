#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    vector<pair<int, int>> l(n), r(n);
    for(int i = 0; i < n; i++)
    {
        int a,b,g,k;
        cin>>a>>b>>g>>k;
        l[i] = make_pair(a, b);
        r[i] = make_pair(a+g, b+k);
    }
    int x, y;cin>>x>>y;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        if(x>=l[i].first&&x<=r[i].first&&y>=l[i].second&&y<=r[i].second) ans = i+1;
    }
    cout<<ans<<endl;
    return 0;
}
