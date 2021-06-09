#include<iostream>
#include<string.h>
#include<cwchar>

using namespace std;

class A
{
    public:
        bool t1() {return true;}
};

struct B: A
{
    int b;
};

int main()
{
    string s = "test2";
    std::cout << s << std::endl;
    const char * ss = "1234";
    std::cout << ss << std::endl;
    string msg = s;
    msg.append(ss+1);
    msg.push_back(ss[0]);
    std::cout << ss << endl;
    std::cout << msg << std::endl;
    int a = 7;
    switch(a)
    {
        case 1:
            std::cout << 1 << std::endl;
            [[fallthrough]];
        case 2:
            std::cout << 2 << std::endl;
            [[fallthrough]];
        case 3:
            std::cout << 3 << std::endl;
            [[fallthrough]];
        case 4:
            std::cout << 4 << std::endl;
            [[fallthrough]];
        case 5:
            std::cout << 5 << std::endl;
            [[fallthrough]];
        case 6:
            std::cout << 6 << std::endl;
            return 0;
        default:
            std::cout << "default" << std::endl;
    }
    string v = "\\\\\\123\\(\\)";
    for(size_t i = 0; i < v.size(); i++)
    {
        if(v[i] == '\\')
            std::cout << i << std::endl;
    }
    std::cout << v << std::endl;
    string zh = "我";
    cout << zh << endl;
    const char * c = zh.c_str();
    cout << strlen(c) << endl;
    cout << strlen("123") << endl;
    const wchar_t * str = L"董睿";
    cout << wcslen(str) << endl;
    B b;
    cout << b.t1() << endl;
    return 0;
}
