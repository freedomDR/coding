#include <bits/stdc++.h>

using namespace std;

int main()
{
    double r, n;
    while(cin>>r>>n){
        double ans = pow(r, n);
        printf("%.15lf\n", ans);
    }
    return 0;
}
