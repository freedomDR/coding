#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int y = 0;
        int ans = 0;
        for (size_t i = 1; i < n+1; i++)
        {
            int x; cin >> x;
            y = max(x, y);
            if(y == i) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}