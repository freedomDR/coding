#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin>>t[i];
    int ans = 0, ones = 0, twos = 0;
    for(int i = 0; i < n; i++)
    {
        while(i+1<n && t[i+1]==t[i]) {t[i]==1?ones++:twos++;i++;}
        ans = max(ans, min(ones, twos)*2);
        if(i+1 == n) break;
        t[i+1] == 1?ones = 1: twos = 1;
    }
    cout<<ans<<endl;
    return 0;
}
