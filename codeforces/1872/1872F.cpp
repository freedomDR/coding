#include <bits/stdc++.h>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n; std::cin >> n;
        std::vector<int> a(n), c(n);
        for(int i = 0; i < n; i++) 
        {
            std::cin >> a[i];
            a[i]--;
        }
        for(int i = 0; i < n; i++) std::cin >> c[i];
        std::vector<int> deg(n, 0), ans;
        std::vector<bool> vis(n);
        for(int i = 0; i < n; i++) deg[a[i]]++;
        auto dfs = [&](auto self, int x) -> void
        {
            ans.push_back(x);
            vis[x] = true;
            if(--deg[a[x]] == 0)
                self(self, a[x]);
        };
        for(int i = 0; i < n; i++)
        {
            if(deg[i] == 0 && !vis[i])
                dfs(dfs, i);
        }
        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;
            std::vector<int> b, ca;
            for(int j = i; !vis[j]; j = a[j])
            {
                vis[j] = true;
                b.push_back(j);
                ca.push_back(c[j]);
            }
            int p = std::min_element(ca.begin(), ca.end())-ca.begin();
            for(int j = 0; j < b.size(); j++)
            {
                ans.push_back(b[(p+j+1)%b.size()]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            std::cout << ans[i]+1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
