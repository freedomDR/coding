#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w, h;
    cin >> w >> h;
    int mod = 998244353, ans = 1;
    for(int i = 0; i < w+h; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
