#include <bits/stdc++.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

using namespace std;

int main()
{
    fmt::print("hello world\n");
    fmt::print(fmt::fg(fmt::color::crimson)|fmt::emphasis::bold, "hello, {}!\n", "world");
    vector<int> arr = {1, 2, 3, 4};
    fmt::print("{}\n", arr);
    return 0;
}
