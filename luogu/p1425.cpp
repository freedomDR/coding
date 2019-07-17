#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int start = a*60+b, end = c*60+d;
    cout<<(end-start)/60<<" "<<(end-start)%60<<endl;
    return 0;
}
