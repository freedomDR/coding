#include <iostream>
#include <memory>
#include <string>

struct T1 {
    int mem1;
    std::string mem2;
};

struct Foo {
    int mem;
    explicit Foo(int n) : mem(n) {}
};

int main(int argc, char *argv[]) {
    std::string s1("test");
    std::string s2(10, 'a');

    std::unique_ptr<int> p(new int(1));

    Foo f(2);

    std::cout << s1 << ' ' << s2 << ' ' << *p << ' ' << f.mem << std::endl;

    return 0;
}
