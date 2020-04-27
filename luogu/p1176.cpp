#include<bits/stdc++.h>

using namespace std;
const int mod = 100003;
int f[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        s.insert(make_pair(a, b));
    }
    f[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[j] = f[j] + f[j-1];
            f[j] %= mod;
            if(s.count(make_pair(i, j)) == 1) {f[j] = 0;}
        }
        // for(int j = 1; j <= n; j++) cout << f[j] << " ";
        // cout << endl;
    }
    cout << f[n] << endl;
    return 0;
}