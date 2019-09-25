#include<bits/stdc++.h>
using namespace std;
struct temp
{
    int v, p;

    bool operator < (const temp x) const 
    {
        return v > x.v;
    }
}a[1100];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int v; cin >> v;
        a[i].v = v;
        a[i].p = i;
    }
    sort(a+1, a+n+1);
    int ans = 0, x = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += a[i].v * x + 1;
        x++;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        cout << a[i].p << " " ;
    return 0;
}
