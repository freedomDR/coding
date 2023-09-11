#include <bits/stdc++.h>


int main()
{
    int q;
    std::cin >> q;
    while(q--)
    {
        int m, x; std::cin >> m >> x;
        std::cout << (x%m==0?m:x%m) << std::endl;
    }
    return 0;
}
