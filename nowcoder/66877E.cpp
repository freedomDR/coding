#include <bits/stdc++.h>

int main()
{
    int n, m;
    std::cin >> n >> m;
    if(n<7)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    long long a = 1;
    for(int i = 0; i < 7; i++) a *= 6;
    a%=10;
    a=a*n;
    a%=10;
    if(m==0)
        std::cout << (a)%10 << std::endl;
    else if(m==1)
        std::cout << (a*a)%10 << std::endl;
    else
        std::cout << (a*a*a*a)%10 << std::endl;
    return 0;
}
