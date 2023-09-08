#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        long long v = std::lcm(x, y);
        long long l = n/x - n/v, r = n/y - n/v;
        long long ans = (n+n-l+1)*l/2-(1+r)*r/2;
        cout << ans << endl;
    }
    return 0;
}
