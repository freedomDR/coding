#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        bool ok;
        if(x == y) ok = true;
        else if(y == 1) ok = true;
        else if(x == 1) ok = false;
        else if(x >= 4) ok = true;
        else if(y <= 3) ok = true;
        else ok = false;
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}
