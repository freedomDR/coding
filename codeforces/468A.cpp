#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, ans = 0;
    cin>>a>>b;
    int res = abs(a-b);
    if(res%2 == 1){
        ans += res/2 + 1;
    }
    res /= 2;
    int mid = 0;
    mid = (res/2) * (res + 1);
    if(res%2 == 1)
        mid += res/2+1;
    mid *= 2;
    ans = ans+mid;
    cout<<ans<<endl;
    return 0;
}
