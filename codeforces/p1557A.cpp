#include<iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        double sums = 0, maxv = -(1e9);
        for(int i = 0; i < n; i++)
        {
            double v; cin >> v;
            sums += v;
            maxv = max(maxv, v);
        }
        // cout << maxv << " " << sums << endl;
        double ans = maxv + (sums-maxv)/(n-1);
        printf("%0.7f\n", ans);
    }
    return 0;
}