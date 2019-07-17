#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0, f = 0;
    for(int i = 0; i < 7; i++){
        int s, e;cin>>s>>e;
        if(s+e<=8) continue;
        if(s+e > ans) ans = s+e, f = i+1;
    }
    if(ans == 0) cout<<ans<<endl;
    else cout<<f<<endl;
    return 0;
}
