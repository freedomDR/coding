#include <bits/stdc++.h>

int main()
{
    std::string s;
    std::cin >> s;
    int a = 0, b = 0, ans = 0;
    for(auto c:s)
    {
        if(c == 'a') a++;
        else b++;
        if(a==0) ans += 2;
        else if(a < 10) ans += 1;
        else if(a%10 == 0) ans += 1;

        if(b==0) ans += 2;
        else if(b < 10) ans += 1;
        else if(b%10 == 0) ans += 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
