#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s;
    getline(cin, s);
    int ans = 0;
    for (auto c : s) {
       if (c == ' ' || c == '\n')
           continue;
        ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}
