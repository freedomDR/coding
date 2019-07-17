#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin>>l[i]>>r[i];
    int k;
    cin>>k;
    for(int i = 0; i < n; i++)
    {
        if(k>=l[i]&&k<=r[i])
        {
            cout<<n-i<<endl;
            return 0;
        }
    }
    return 0;
}
