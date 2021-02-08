#include<iostream>

using namespace std;
long long a, b;

void fast_pow()
{
    long long base = a, ret = 1;
    while(b > 0)
    {
        if(b&1) ret *= base;
        b >>= 1;
        base *= base;  
    }
    cout << ret << endl;
}

int main()
{
    cin >> a >> b;
    fast_pow();
    return 0;
}