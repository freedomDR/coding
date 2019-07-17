#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int sums = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(sums + a[i] > m)
        {
            ans++; sums = a[i]; 
        }else
        {
            sums += a[i];
        }
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}
