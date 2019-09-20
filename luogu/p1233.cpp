#include<bits/stdc++.h>
using namespace std;

struct T
{
    int l, w;
    bool operator < (const T &x) const {
        return l == x.l ? w > x.w : l > x.l;
    }
}t[5050];

int f[5050];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i].l >> t[i].w;
    sort(t, t+n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(t[i].w > t[j].w) f[i] = max(f[i], f[j]+1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans+1 << endl;
    return 0;
}
