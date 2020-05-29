#include <iostream>
 
using namespace std;
 
class A
{
public:
    A(){cout<<"construct1..............."<<endl;}
    A& operator = (const A&&) {cout<<" operator move"<<endl;}
    A(const A&&){cout<<"move construct "<<endl;}
 
    A& operator = (const A&){cout<<"copy operator"<<endl;}
    A(const A&){cout<<"copy construct"<<endl;}
};
int main()
{   
    A a1 = A();  // 这里调用的到底是哪一个构造函数?
    A a2 = std::move(A()); // 调用什么呢？
       a2 = A();//调用operator =(const A&&)
   
    A&& a = A();//只调用默认构造
    a2 = a1;
    return 0;
}