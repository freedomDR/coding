#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m;
    int q;
    cin >> n >> m >> q;
    long long g = __gcd(n, m);
    while(q--) {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--; ey--;
        if(sx == 1) sy /= (n/g);
        else sy /= (m/g);
        if(ex == 1) ey /= (n/g);
        else ey /= (m/g);
        cout << (sy==ey?"YES":"NO") << endl;
    }
    return 0;
}
