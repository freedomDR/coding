#include <bits/stdc++.h>
#include <memory>

using namespace std;

void test_catch_nullptr_exception()
{
    struct A 
    {
        int a;
    };
    auto a = std::make_shared<A>();
    a = nullptr;
    try 
    {
        std::cout << a->a << std::endl;
    }
    catch (...)
    {
        std::cout << "catch nullptr exception\n";
    }
}

int main()
{
    test_catch_nullptr_exception();
    return 0;
}