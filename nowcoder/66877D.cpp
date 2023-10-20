#include <bits/stdc++.h>

void slove()
{
    int n; std::cin >> n;
    int ans = 1e9;
    for(int i = 0; i < 20; i++)
    {
        int cur = n, cnt = 0;
        while(cur%2==0)
        {
            cur /= 2;
            cnt++;
        }
        ans = std::min(ans, i+std::max(0, (20-cnt)));
        n++;
    }
    std::cout << ans << std::endl;
}

int main()
{
    int T; std::cin >> T;
    while(T--)
    {
        slove();
    }
    return 0;
}
