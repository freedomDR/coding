#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    int a_max = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        a_max = max(a_max, a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a_max == a[i])
        {
            int tmp = 0;
            while(i < n && a_max == a[i]) i++, tmp++;
            ans = max(ans, tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}
