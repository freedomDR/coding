#include <bits/stdc++.h>
#include <bitset>
#include <tuple>
#include <unordered_map>
#include <vector>

using ll = long long;

void dfs(int l, int r, ll sums, std::vector<ll> &a, int state, std::unordered_map<ll, std::vector<int>> &cnt)
{
    if(l >= r)
    {
        cnt[sums].push_back(state);
        return;
    }
    dfs(l+1, r, sums, a, state, cnt);
    dfs(l+1, r, sums-a[l], a, state|(1<<l), cnt);
    dfs(l+1, r, sums+a[l], a, state|(1<<l), cnt);
}

int main()
{
    int n; std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    std::unordered_map<ll, std::vector<int>> l_cnt, r_cnt;
    dfs(0, n/2, 0, a, 0, l_cnt);
    dfs(n/2, n, 0, a, 0, r_cnt);
    /* for(auto &v:l_cnt) */
    /* { */
    /*     std::cout << v.first << "--"; */
    /*     for(auto c:v.second) */
    /*         std::cout << c << " "; */
    /*     std::cout << std::endl; */
    /* } */
    /* for(auto &v:r_cnt) */
    /* { */
    /*     std::cout << v.first << "--"; */
    /*     for(auto c:v.second) */
    /*         std::cout << c << " "; */
    /*     std::cout << std::endl; */
    /* } */
    ll ans = 0;
    std::bitset<(1<<20)> vis;
    for(auto &v:l_cnt)
    {
        ll key = v.first;
        for(auto l_state:v.second)
        {
            if(r_cnt.count(-key)==0) continue;
            for(auto r_state:r_cnt[-key])
            {
                if(!vis[(l_state|r_state)])
                {
                    ans++;
                    vis.set(l_state|r_state);
                }
            }
        }
        /* std::cout << key << ": " << ans << std::endl; */
    }
    ans--;
    std::cout << ans << std::endl;
    return 0;
}
