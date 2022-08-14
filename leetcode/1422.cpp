#include <bits/stdc++.h>

int slove(std::string s)
{
    int ans = 0;
    int pre0 = 0, suf1 = 0;
    for (auto& c: s) {
        if(c == '1') suf1++;
    }
     for (int i = 0; i < (int)s.size()-1; i++) {
         if(s[i] == '1') suf1--;
         else pre0++;
         ans = std::max(ans, pre0 + suf1);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    std::string s;
    std::cin >> s;
    auto ret = slove(s);
    std::cout << ret << std::endl;
    return 0;
}
