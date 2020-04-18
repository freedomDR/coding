#include<bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("P1158_2.in", "r", stdin);
    int x1, x2, y1, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    auto f = [](int x1, int y1, int x2, int y2)
    {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    };
    auto cmp = [&](auto a1, auto a2)
    {
        return f(x1, y1, a1.first, a1.second) < f(x1, y1, a2.first, a2.second);
    };
    sort(a.begin(), a.end(), cmp);
    int d1 = 0, d2 = 0, ans = INT_MAX;
    for(int i = n-1; i >= 0; i--)
    {
        d1 = f(x1, y1, a[i].first, a[i].second);
        if(i+1 != n) d2 = max(d2, f(x2, y2, a[i+1].first, a[i+1].second));
        ans = min(ans, (d1+d2));
    }
    cout << ans << endl;
    return 0;
}