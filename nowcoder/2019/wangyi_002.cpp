#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l, r;
    cin >> l >> r;
    auto func = [](int x) {return (x+2)/3;};
    cout << r-l+1-(func(r)-func(l-1)) << endl;
    return 0;
}
