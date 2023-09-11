#include <bits/stdc++.h>


int main()
{
    int q;
    std::string s;
    std::cin >> s;
    int sums = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int cnt1 = 0, cnt2 = 0;
        for(int j = i; j < s.size(); j++)
        {
            if(j%2)
            {
                if(s[j] == '0') cnt1++;
                else cnt2++;
            }
            else 
            {
                if(s[j] == '0') cnt2++;
                else cnt1++;
            }
            sums += std::min(cnt1, cnt2);
        }
    }
    std::cout << sums << std::endl;
    return 0;
}
