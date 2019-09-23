#include<bits/stdc++.h>
using namespace std;
int a[200010], b[200010];
int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans ^= (a[i]+b[j]);
        }
    }
    cout << ans << endl;
}
