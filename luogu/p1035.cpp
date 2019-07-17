#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, k;cin>>k;
    for(double v = 0; v <= k; ++n, v+=1.0/n) ;
    cout<<n<<endl;
    return 0;
}
