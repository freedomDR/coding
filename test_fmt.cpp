#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include <memory>

using namespace std;

class T 
{
    int a;
};

using tPtr = std::unique_ptr<T>;

tPtr makeT()
{
    return {};
}

int main()
{
    fmt::print("hello world\n");
    fmt::print(fmt::fg(fmt::color::crimson)|fmt::emphasis::bold, "hello, {}!\n", "world");
    vector<int> arr = {1, 2, 3, 4};
    fmt::print("{}\n", arr);
    auto p = makeT();
    if(p == nullptr)
        fmt::print("p is nullptr \n");
    return 0;
}
