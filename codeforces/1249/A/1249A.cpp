#include<bits/stdc++.h>
using namespace std;
int m[101];
int main()
{
    int q; cin >> q;
    while(q--)
    {
        int n; cin >> n;
        int ans = 1;
        memset(m, 0, sizeof(m));
        for(int i = 0; i < n; i++) 
        {
            int v; cin >> v;
            if(m[v-1]||m[v+1]) ans = 2;
            m[v] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}
