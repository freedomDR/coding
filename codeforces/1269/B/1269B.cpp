#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto &v:a) 
    {
        cin >> v;
        v %= m;
    }
    for(auto &v:b)
        cin >> v;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int x = (b[0]-a[i]+m)%m;
        bool ok = true;
        for(int j = 0; j < n; j++)
        {
            if((a[(i+j)%n]+x)%m != b[j]) {ok=false;break;}
        }
        if(ok) ans = min(ans, x);
    }
    cout << ans << endl;
    return 0;
}

