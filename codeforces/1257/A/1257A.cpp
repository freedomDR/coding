#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if(a > b) swap(a, b);
        int ans = (b-a)+x;
        ans = min(ans, n-1);
        cout << ans << endl;
    }
    return 0;
}
