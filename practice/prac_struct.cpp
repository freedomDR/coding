#include <bits/stdc++.h>

typedef struct AA
{
    int val1;
    int val2;
}A;

typedef struct BB
{
    BB *pre;
    BB *next;
}BBB;

int main()
{
    AA a[2] = {{1,2}, {3,4}};
    A b[2] = {{1,2}, {3,4}};
    for(int i = 0; i < 2; i++)
    {
        std::cout << a[i].val1 << " " << a[i].val2 << std::endl;
        std::cout << b[i].val1 << " " << b[i].val2 << std::endl;
    }
    BBB *bb = new BB();
    struct BB *bb2 = new BB();
    struct BB bb3(nullptr, nullptr), bb4(nullptr, nullptr);
    std::cout << "bb " << bb->pre << " " << bb->next << std::endl;
    std::cout << "bb2 " << bb2->pre << " " << bb2->next << std::endl;
    std::cout << "bb3 " << bb3.pre << " " << bb3.next << std::endl;
    std::cout << "bb4 " << bb4.pre << " " << bb4.next << std::endl;
    delete bb;
    return 0;
}
