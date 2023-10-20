#include <bits/stdc++.h>

int main()
{
    int n; std::cin >> n;
    int ans = 0;
    while(n!=0&&n%2)
    {
        n /= 10;
        ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}
