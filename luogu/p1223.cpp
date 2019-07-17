#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> t(n, make_pair(0, 0));
    for(int i = 0; i < n; i++)
    {
        int v; cin >> v;
        t[i].first = v;
        t[i].second = i+1;
    }
    double ans = 0.0;
    sort(t.begin(), t.end(), [](auto t1, auto t2) { return t1.first < t2.first;});
    for(int i = 0, nn = n-1; i < n; i++)
    {
        cout<<t[i].second<<" ";
        ans += nn*t[i].first;   
        nn--;
    }
    ans /= n;
    printf("\n%0.2f\n", ans);
    return 0;
}
