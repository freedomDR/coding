#include <bits/stdc++.h>
#include <algorithm>

using ll = long long;

void dfs(int l, int r, ll sums, ll M, std::vector<ll> &a, std::vector<ll> &cnt)
{
    if(l >= r)
    {
        cnt.push_back(sums);
        return;
    }
    /* std::cout << "dfs: " << l << " " << r << std::endl; */
    dfs(l+1, r, sums, M, a, cnt);
    if(sums+a[l]<=M)
        dfs(l+1, r, sums+a[l], M, a, cnt);
}

int main()
{
    ll N, M;
    std::cin >> N >> M;
    std::vector<ll> a(N);
    for(int i = 0; i < N; i++) std::cin >> a[i];
    ll ans = 0;
    std::vector<ll> lsums, rsums;
    dfs(0, N/2, 0, M, a, lsums);
    dfs(N/2, N, 0, M, a, rsums);
    /* for(auto v:lsums) */
    /*     std::cout << v << " "; */
    /* std::cout << std::endl; */
    /* for(auto v:rsums) */
    /*     std::cout << v << " "; */
    /* std::cout << std::endl; */
    std::sort(lsums.begin(), lsums.end());
    for(int i = 0; i < rsums.size(); i++)
    {
        ans += std::upper_bound(lsums.begin(), lsums.end(), M-rsums[i])-lsums.begin();
    }
    std::cout << ans << std::endl;
    return 0;
}
