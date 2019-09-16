#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> v(m), p(m), f(n+1);
    for(int i = 0; i < m; i++) cin >> v[i] >> p[i];
    for(int i = 0; i < m; i++) 
    {
        for(int j = n; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j-v[i]]+v[i]*p[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}
