#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    cin>>n;
    int ans = -10000000;
    for(int i = 0; i < n; i++){
        cin>>a;
        if(a < 0 || a - pow((int)sqrt(a), 2) != 0)
            ans = max(ans, a);
    }
    cout<<ans<<endl;
    return 0;
}
