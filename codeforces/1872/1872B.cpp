#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    int n;
    vector<pair<int, int>> trap;
    while(t--)
    {
        trap.clear();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int di, si; cin >> di >> si;
            trap.emplace_back(make_pair(di, si));
        }
        std::sort(trap.begin(), trap.end(), [](auto &l, auto &r){return l.first < r.first;});
        int ans = 100000;
        for(int i = 0; i < n; i++)
        {
            int di = trap[i].first, si = trap[i].second;
            if(di >= ans) break;
            ans = min(ans, di + (si-1)/2);
        }
        cout << ans << endl;
    }
    return 0;
}
