#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 1, b = 1, c = 1;
    auto m1 = [a, &b, &c]() mutable {
        cout<<a<<endl;
        auto m2 = [a, b, &c]() mutable {
            cout<<a<<b<<c<<endl;
            a = 4, b = 4, c = 4;
        };
        a = 3, b = 3, c = 3;
        m2();
    };
    a = 2, b = 2, c = 2;
    m1();
    cout<<a<<b<<c<<endl;
    int d = 1;
    auto g = [=]() mutable {
        auto gg = [=](int y){
            return d+y;
        };
        d = 2;
        return gg;
    };
    d = 3;
    cout<<g()(3)<<endl;
    int e = 1;
    e = 2;
    auto ee = [e](){cout<<e<<endl;};
    ee();
    return 0;
}
