#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

std::string slove(std::string s)
{
    std::vector<char> a, b;
    for (auto c : s) {
        if(c >= '0' && c <= '9') b.push_back(c);
        else a.push_back(c);
    }
    fmt::print("{} {} \n", a, b);
    fmt::print("{}\n", a.size()-b.size());
    fmt::print("{}\n", b.size()-a.size());
    if((int)a.size()-(int)b.size() >= 2) return "";
    if((int)b.size()-(int)a.size() >= 2) return "";
    std::string ans;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size())
    {
        ans.push_back(a[i++]);
        ans.push_back(b[j++]);
    }
    if(i != a.size()) ans.push_back(a[i]);
    if(j != b.size()) ans.insert(ans.begin(), b[j]);
    return ans;
}

int main(int argc, char *argv[])
{
    std::string s;
    std::cin >> s;
    auto ret = slove(s);
    fmt::print("{}\n", ret);
    return 0;
}
