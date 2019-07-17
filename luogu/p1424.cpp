#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, n, ans = 0, f;
    cin>>x>>n;
    while(n > 0 && x < 8) {if(x < 6) ans+=250;x++;n--;}
    ans += (n/7)*1250 + min((n%7)*250, 1250ll); 
    cout<<ans<<endl;
    return 0;
}
