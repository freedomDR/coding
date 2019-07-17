#include <bits/stdc++.h>

using namespace std;
int n,b;

int main()
{
    int ans = 0;
    cin>>n;
    while(n-- > 0){
        cin>>b;
        if(b >= 0) ans += b;
        else ans -= b;
    }
    cout<<ans<<endl;
    return 0;
}
