#include <bits/stdc++.h>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) 
        {
            std::cin >> a[i];
        }
        std::string s; std::cin >> s;
        std::vector<int> sum(n+1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ans ^= a[i];
            sum[i+1] = sum[i]^a[i];
        }
        int q; std::cin >> q;
        while(q--)
        {
            int t; std::cin >> t;
            if(t == 1)
            {
                int l, r; std::cin >> l >> r;
                l--;
                ans ^= sum[l]^sum[r];
            }
            else
            {
                int g; std::cin >> g;
                if(g == 1)
                    std::cout << ans << " ";
                else
                    std::cout << (ans^sum[n]) << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

