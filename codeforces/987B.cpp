#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x, y;
    cin>>x>>y;
    long double a1 = y * log(x);
    long double a2 = x * log(y);
    long double res = a1 - a2;
    if(res > 0) cout<<">"<<endl;
    else if(res < 0) cout<<"<"<<endl;
    else cout<<"="<<endl;
    return 0;
}
