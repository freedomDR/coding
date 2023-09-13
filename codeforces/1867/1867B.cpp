#include <iostream>
#include <string>

int main()
{
    int t; std::cin >> t;
    while(t--)
    {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        int l = 0, r = 0;
        for(int i = 0; i < n-1-i; i++)
        {
            if(s[i] == s[n-1-i])
                r += 2;
            else 
            {
                l++;r++;
            }
        }
        std::string ans(n+1, '0');
        for(int i = l; i <= r; i += 2)
        {
            ans[i] = '1';
            if(n%2==1)
                ans[i+1] = '1';
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
