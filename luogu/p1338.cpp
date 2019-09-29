#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans(n+1);
    int l = 1, r = n;
    for(int i = 1; i <= n; i++)
    {
        int t = (ll)(n-i)*(n-i-1)/2;
        if(t >= m) ans[l++] = i;
        else ans[r--] = i, m -= (r-l+1);
    }   
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
