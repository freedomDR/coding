#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, x2, y1, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool ok = true;
        if(y1 == y2 && c+d>0) ok = false;
        if(x1 == x2 && a+b>0) ok=false;
        if(a>b&&x-(a-b)<x1) ok = false;
        if(b>a&&(x+(b-a))>x2) ok = false;
        if(c<d&&(y+(c-d))>y2) ok = false;
        if(d<c&&(y-(d-c))<y1) ok = false;
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}