#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    long long a_sum = 0;
    for(int i = 0; i < n; i++) {cin>>a[i];a_sum += a[i];}
    if(a_sum < m) {cout<<"-1"<<endl;return 0;}
    if(a_sum == m) {cout<<n<<endl;return 0;}
    sort(a.begin(), a.end(), greater<int>());
    int l = 1, r = n;
    while(l<r)
    {
        int mid = (l+r)/2;
        a_sum = 0LL;
        for(int i = 0; i < n; i++)
            a_sum+=max(a[i]-i/mid, 0);
        if(a_sum>=m) r=mid;
        else l=mid+1;
    }
    cout<<r<<endl;

    return 0;
}
