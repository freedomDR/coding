#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int t1 = max(a*2, b);
        int t2 = max(b*2, a);
        int t3 = a+b;
        int t = min(t1, min(t2, t3));
        cout << t*t << endl;
    }
    return 0;
}