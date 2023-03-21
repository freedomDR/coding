#include <iostream>
#include <string>
#include <vector>

struct T1 {
    int mem1;
    std::string mem2;
};

struct T2 {
    int mem1;
    std::string mem2;
    T2(const T2 &) {}
};

struct T3 {
    int mem1;
    std::string mem2;
    T3() {}
};

std::string s{};

int main(int argc, char *argv[]) {
    int n{};
    double f = double{};
    int *a = new int[10]{};

    T1 t1{};
    T3 t3{};

    std::vector<int> v(3);
    std::cout << s.size() << ' ' << n << ' ' << f << ' ' << a[9] << ' ' << v[2]
              << std::endl;
    std::cout << t1.mem1 << ' ' << t3.mem1 << std::endl;
    delete[] a;

    return 0;
}
