#include <bits/stdc++.h>

int main()
{
    long long a, b;
    int k;
    std::cin >> k >> a >> b;
    std::set<long long> s;
    s.insert(a);
    s.insert(b);
    long long min_c = -1;
    while(k--)
    {
        min_c = *s.begin();
        s.insert(min_c+a);
        s.insert(min_c+b);
        s.erase(s.begin());
    }
    std::cout << min_c << std::endl;
    return 0;
}
