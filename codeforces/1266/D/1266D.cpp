#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> bal(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, z;
        cin >> u >> v >> z;
        bal[--u] += z;
        bal[--v] -= z;
    }
    vector<pair<int, long long>> neg;
    for(int i = 0; i < n; i++)
    {
        if(bal[i] < 0)
            neg.emplace_back(i, -bal[i]);
    }
    vector<tuple<int, int, long long>> ret;
    for(int i = 0; i < n; i++)
    {
        while(bal[i] > 0)
        {
            long long val = min(bal[i], neg.back().second);
            ret.emplace_back(i, neg.back().first, val);
            bal[i] -= val;
            neg.back().second -= val;
            if(neg.back().second == 0)
                neg.pop_back();
        }
    }
    cout << ret.size() << endl;
    for(auto &it:ret)
    {
        cout << get<0>(it)+1 << " " << get<1>(it)+1 << " " << get<2>(it) << endl;
    }
    return 0;
}
