#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, ans = 0, divisor = 10;
    cin>>n>>x;
    while(divisor <= n*10)
    {
        ans += (n/divisor)*(divisor/10);
        ans += min(divisor/10, max(0, (n%divisor)-(divisor*x/10)+1));
        divisor *= 10;
    }
    if(x == 0)
    {
        for(int i = 1; i <= n; i*=10)
        {
            ans -= i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
