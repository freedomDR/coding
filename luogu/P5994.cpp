#include <bits/stdc++.h>

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::map<int, std::set<int>> f;
    for(size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            int x; std::cin >> x;
            f[x].insert(j);
        } 
    }
    for (size_t i = 1; i <= k; i++)
    {
        std::cout << f[i].size() << " ";
    }
    return 0;
}