#include <bits/stdc++.h>


int main()
{
    int q;
    std::cin >> q;
    while(q--)
    {
        int n, k; std::cin >> n >> k;
        std::vector<int> arr(n);
        int cnt = 1;
        for(int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
        auto update = [&](int pos, int add) -> void
        {
            arr[pos] += add;
        };
        while(k--)
        {
            int u, v; std::cin >> u >> v;
            u--;v--;
            update(u, 1);
            update(v, -1);
        }
        for(int i = 1; i < n; i++)
        {
            if(arr[i]>=arr[i-1]) cnt++;
        }
        std::cout << (cnt==n?"Yes":"No") << std::endl;
    }
    return 0;
}
