#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        int ret = b-a;
        int ll = c-r, rr = c+r;
        cout << ret-(max(0, min(b, rr)-max(a, ll))) << endl;
    }
    return 0;
}
