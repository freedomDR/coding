#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0?a:gcd(b, a%b);
}

int main()
{
    int n; cin >> n;
    long long g = 0;
    for(int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        g = gcd(g, v);
    }
    int ans = 0;
    for(int i = 1; i * 1LL * i <= g; i++) {
        if(g%i == 0) {
            ans+=2;
            if(g/i == i) ans--;
        }        
    }
    cout << ans << endl;
    return 0;
}
