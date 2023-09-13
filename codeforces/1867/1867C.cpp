#include <bits/stdc++.h>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n; std::cin >> n;
        std::vector<int> cnt(n+1);
        for(int i = 0; i < n; i++)
        {
            int x; std::cin >> x;
            if(x <= n)
                cnt[x]++;
        }
        int mex = 0;
        while(cnt[mex]) mex++;
        while(true)
        {
            std::cout << mex << std::endl;
            int x; std::cin >> x;
            if(x == -1)
                break;
            mex = x;
        }
    }
    return 0;
}
