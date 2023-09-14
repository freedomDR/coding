#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n, k; std::cin >> n >> k;
        int pos = 0;
        int ans = 0;
        for(; pos+k <= n; pos += k)
        {
            std::cout << "? " << pos+1 << std::endl;
            int x; std::cin >> x;
            ans ^= x;
        }
        int t = n-pos;
        std::cout << "? " << (n-k-t/2+1) << std::endl;
        int x; std::cin >> x;
        ans ^= x;
        std::cout << "? " << (n-k+1) << std::endl;
        std::cin >> x;
        ans ^= x;
        std::cout << "! " << ans << std::endl;
    }
    return 0;
}
