#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n), b(n), c(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        long long sums = 0;
        for(int i = 0; i < n; i++)
        {
            c[(i+1)%n] = max(0ll, a[(i+1)%n]-b[i]);
            sums += c[(i+1)%n];
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, sums-c[i]+a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}