#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++)
            std::cin >> a[i];
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int l, int r){return a[l]>a[r];});
        std::vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[p[i]] = i+1;
        for(int i = 0; i < n; i++)
            std::cout << ans[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}
