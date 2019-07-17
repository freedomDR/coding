#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int ans = -1;
    for(int i = 0; i < n || i+ans<=n; i++)
    {
        int j = i+1, ii = i;
        while(j < n && a[j]-a[ii] <= 5) 
        {
            j++;
            if(a[ii] == a[j]) i++;
        }
        ans = max(ans, j-ii);
    }
    cout<<ans<<endl;
    return 0;
}
