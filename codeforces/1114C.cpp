#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, b;
    cin>>n>>b;
    long long ans = 1e18;
    for(long long i = 2; i <= b; i++){
        if(1LL*i*i>b) i = b;
        long long bi = 0;
        while(b%i == 0) bi++, b /= i;
        if(bi == 0) continue;
        long long ni = 0, tmp = 1;
        while(tmp <= n/i) {tmp*=i;ni += n/tmp;}
        /* cout<<bi<<" "<<ni<<endl; */
        ans = min(ans, ni/bi);
    }
    cout<<ans<<endl;
    return 0;
}
