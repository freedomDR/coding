#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, r, a, ans;
    cin>>l>>r>>a;
    if(l == r){
        ans = l + a/2;
    }else if(l < r){
        ans = min(l+a,r) + ((a>(r-l))?((a-r+l)/2):0);
    }else{
        ans = min(l, r+a) + ((a>(l-r))?((a-l+r)/2):0);
    }
    ans *= 2;
    cout<<ans<<endl;
    return 0;
}
