#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    nth_element(a.begin(),a.begin()+2, a.end(), greater<int>());
    int a1 = max(a[0], a[1]), a2 = min(a[0], a[1]);
    long long ans = (1LL*a1*k+a2)*(m/(k+1))+1LL*(m%(k+1))*a1;
    cout<<ans<<endl;
    return 0;
}
