#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct Vtemp
{
    long long x1, y1;
    long long x2, y2;
}Rect;
ll calc(Rect &r1, Rect &r2)
{
    ll ans = 0;
    return ans;
}

int main()
{   
    Rect r1, r2, r3;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    cin >> r3.x1 >> r3.y1 >> r3.x2 >> r3.y2;
    cout << ((r1.x2-r1.x1)*(r1.y2-r1.y1)-calc(r1, r2)-calc(r1, r3)+calc(r2, r3) > 0?"YES":"NO") << endl;
    return 0;
}
