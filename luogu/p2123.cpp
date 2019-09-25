#include<bits/stdc++.h>
using namespace std;

struct temp
{
    int a, b, d;
    bool operator < (const temp x) const
    {
            if(d != x.d) return d < x.d;
            else if(d <= 0) return a < x.a;
            else return b > x.b;
    }
}c[20010];
long long a[20010];
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            c[i].a = a; c[i].b = b;
            if(a < b) c[i].d = -1;
            else if(a == b) c[i].d = 0;
            else c[i].d = 1;
        }
        sort(c+1, c+n+1);
        long long s = 0;
        for(int i = 1; i <= n; i++)
        {
            s += c[i].a;
            a[i] = max(a[i-1], s) + c[i].b;
        }
        cout << a[n] << endl;
    }   
    return 0;
}
