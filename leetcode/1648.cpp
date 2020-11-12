#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;
const int mod = 1e9+7;

int slove(vector<int> &arr, int m)
{
    long long ans = 0;
    map<int, int> mp;
    for(auto v:arr)
        mp[v]++;
    priority_queue<pair<int, int>> pq;
    for(auto &it:mp)
        pq.push({it.first, it.second});
    while(m)
    {
        auto [firstK, firstV] = pq.top();
        pq.pop();
        if(pq.empty())
        {
            // m must -> 0
            long long quotient = m/firstV, remainder = m%firstV;
            ans += (1ll*quotient*firstK%mod)*firstV%mod - (1ll*(quotient-1)*quotient/2 %mod)* firstV%mod + 1ll*(firstV-quotient)*remainder%mod;
            ans %= mod;
            m = 0;
        }else
        {
            auto [secondK, secondV] = pq.top();
            long long d = firstK-secondK;
            if(d*firstV <= m)
            {
                ans += (1ll*firstK*firstV%mod)*d%mod-((d-1)*d/2%mod) * firstV %mod;
                m -= d*firstV;
                ans %= mod;
                pq.pop();
                pq.push({secondK, secondV+firstV});
            }else
            {
                // m must -> 0
                long long quotient = m/firstV, remainder = m%firstV;
                ans += (1ll*quotient*firstK%mod)*firstV%mod - ((quotient-1)*quotient/2 %mod) * firstV%mod + (firstV-quotient)*remainder%mod;
                ans %= mod;
                m = 0;
            }
        }
    }
    return (int)ans;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &v:arr) cin >> v;
    int m; cin >> m;
    cout << slove(arr, m) << endl;
    return 0;
}