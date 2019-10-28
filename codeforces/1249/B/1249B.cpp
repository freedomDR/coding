#include<bits/stdc++.h>
using namespace std;
int s[200001], e[200001], p[200001];
int main()
{
    int q; cin >> q;
    while(q--)
    {
        int n; cin >> n;
        memset(s, 0, sizeof(s));
        memset(e, 0, sizeof(e));
        memset(p, 0, sizeof(p));
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++)
        {
            if(e[i] > 0) continue;
            int st = p[i], sums = 1;
            while(st != i) {sums++;st = p[st];}
            st = p[i]; e[i] = sums;
            while(st != i) {e[st] = sums;st = p[st];}
        }
        for(int i = 1; i <= n; i++) cout << e[i] << " ";
        cout << endl;
    }
    return 0;
}
