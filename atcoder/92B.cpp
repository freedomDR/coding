#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,x,ans;
    cin>>n>>d>>x;
    ans = 0;
    while(n--){
        int a;
        cin>>a;
        ans += ((d-1)/a + 1);
    }
    cout<<ans+x<<endl;
    return 0;
}
