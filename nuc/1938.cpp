#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c ,d;
    cin>>n;
    a = n/1000;
    n %= 1000;
    b = n/100;
    n %= 100;
    c = n/10;
    n %= 10;
    d = n;
    cout<<(a+c)*100+(b+d)<<endl;

    return 0;
}
