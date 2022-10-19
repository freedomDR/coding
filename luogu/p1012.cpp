#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    vector<string> arr(n);
    for (auto & s : arr) {
        std::cin >> s;
    }
    std::sort(arr.begin(), arr.end(), [](auto & s1, auto & s2) {return s1+s2 > s2+s1;});
    for (auto & s : arr)
        std::cout << s;
    std::cout << std::endl;
    return 0;
}
