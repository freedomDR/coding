#include<bits/stdc++.h>

using namespace std;

int g[105][105];

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, k; cin >> n >> m >> k;
        if((m/2)*n < k)
        {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        memset(g, 0, sizeof(g));
        
    }
    return 0;
}