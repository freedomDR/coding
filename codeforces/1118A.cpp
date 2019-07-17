#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q, a, b;
    long long n;
    cin>>q;
    while(q--){
        cin>>n>>a>>b;
        long long ans = 0;
        if(2*a > b)
        {
            ans = (n/2)*b;
            if(n%2) ans += a;
        }
        else
        {
            ans = a*n;
        }
        cout<<ans<<endl;
    }
    return 0;
}
