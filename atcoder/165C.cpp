#include<bits/stdc++.h>
using namespace std;

int n, m, q, ans;
int w[11][11], f[11][11];
int main()
{
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(w[a][b] < d) {w[a][b] = d; g[a][b] = c;}
    }
    return 0;
}