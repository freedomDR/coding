#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>
#include <thread>
#include <type_traits>
#include <utility>
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

enum tt { ONE, TWO };

int testFunc(const int &a = tt::ONE) {
    std::cout << "a: " << a << std::endl;
    return 1;
}

void testFunc2(int a)
{
    if(a > 10) {
        return;
    }
    std::cout << "hell" << "\n";
}

class TestClass {
   public:
    static int v;
    void test() { std::cout << v << std::endl; }
    std::vector<int> arr;
    int * ptr;
};

class TestClass2 
{
    public:
        int v;
};

int TestClass::v = -1;

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

    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(uint64_t) << std::endl;
    std::string s = "12312312313123";
    // auto vv = static_cast<uint64_t>(s);
    // std::cout << vv << std::endl;
    // std::pair<typename T1, typename T2>
    std::cout << std::to_string(1.123123123131231313f) << std::endl;

    testFunc();
    testFunc(1);
    testFunc(15);
    TestClass t;
    t.test();

    // for (int i = 0; i < 1000; i++) {
    //     std::this_thread::sleep_for(std::chrono::seconds(10));
    // }

    TestClass test_class;
    std::cout << test_class.arr.size() << " " << test_class.ptr << " " << test_class.v << "\n";
    TestClass2 test_class2;
    std::cout << test_class2.v << "\n";

    testFunc2(20);

    char * s1 = "abs";
    std::string s2(s1, 0);
    std::cout << "s2: *" << s2 << "*\n";
    
    struct TmpData 
    {
        int v1;
    };

    auto test_f1 = []() -> const TmpData *
    {
        std::shared_ptr<TmpData> tmp = std::make_shared<TmpData>(1);
        
        return tmp.get();
    };

    const auto * tmp_data_ptr = test_f1();
    std::cout << tmp_data_ptr->v1 << std::endl;

    int test_int = 1;
    auto * test_int_ptr = &test_int;
    std::cout << *test_int_ptr << std::endl;
    return 0;
}
