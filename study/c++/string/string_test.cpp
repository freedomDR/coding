#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

void typeConvertTest() {
    auto a = 1;
    auto b = 1l;
    auto c = 1ll;
    string as =  to_string(a);
    string bs =  to_string(b);
    string cs =  to_string(c);
    stoi(as);
    stol(bs);
    stoll(cs);
}

int main() {
    typeConvertTest();
    return 0;
}