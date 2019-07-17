#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z, a, b, c;
    cin>>x>>y>>z>>a>>b>>c;
    if(x > a)
        cout<<"NO"<<endl;
    else if(x+y>a+b)
        cout<<"NO"<<endl;
    else if(x+y+z>a+b+c)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
