#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        int maxx = 1e5, minx = -(1e5), maxy = 1e5, miny = -(1e5);
        while(n--) {
            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if(!f1) minx = max(minx, x);
            if(!f2) maxy = min(maxy, y);
            if(!f3) maxx = min(maxx, x);
            if(!f4) miny = max(miny, y);
        }
        if(maxx < minx || maxy < miny) cout << "0" << endl;
        else cout << "1 " << maxx << " " << maxy << endl;
    }
    return 0;
}
