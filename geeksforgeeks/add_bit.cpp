/*
 * 位操作 先保存0+1的,再把都是1的左移一位作为另一个加数;
 * 直到加数为零
 */
#include <bits/stdc++.h>

using namespace std;

int add(int a, int b)
{
    while(b != 0)
    {
        int temp = a & b; 
        a = a ^ b;
        b = temp << 1;
    }
    return a;
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<add(a, b)<<endl;
    return 0;
}
