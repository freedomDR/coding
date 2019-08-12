#include<bits/stdc++.h>
using namespace std;
long long b, p, k;
int main()
{
    cin >> b >> p >> k;
    long long ans = 1, base = b%k, pp = p;
    while(p){
        if(p&1) ans *= base;
        base *= base;
        base %= k;
        ans %= k;
        p >>= 1;
    }
    cout << b<< "^" << pp << " mod " << k << "=" << ans%k << endl;
	return 0;
}
