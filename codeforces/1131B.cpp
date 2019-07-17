#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, a1, a2, b1, b2;
    a1 = 0; b1 = 0;
    cin>>n;
    int ans = 1;
    while(n--)
    {
        cin>>a2>>b2;
        if(min(a2,b2) - max(a1,b1) >= 0)
        {
            ans += min(a2,b2)-max(a1,b1);
            if(a1!=b1) ans+=1;
        }
        a1 = a2; b1 = b2;
    }
    cout<<(ans?ans:1)<<endl;
    return 0;
}
