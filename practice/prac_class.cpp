#include <bits/stdc++.h>

typedef struct 
{
    int val1;
    int val2;
}A;

int main()
{
    A a[2] = {{1,2}, {3,4}};
    for(int i = 0; i < 2; i++)
    {
        std::cout << a[i].val1 << " " << a[i].val2 << std::endl;
    }
    return 0;
}
