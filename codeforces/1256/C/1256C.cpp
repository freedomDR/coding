#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m), res(n+2), sums(m);
    for(auto &v:c) cin >> v;
    for(int i = m-1; i >= 0; i--)
    {
        if(i == m-1) sums[i] = c[i];
        else sums[i] = sums[i+1] + c[i];
    }
    int p = 0,cpos = 0, cnt = 1;
    while(cpos != m)
    {
        int nextp = p+d;
        if(n+1-nextp < sums[cpos])
            nextp = n+1-sums[cpos];
        for(int i = p+1; i < nextp; i++)
            res[i] = 0;
        for(int i = nextp; i < nextp+c[cpos]; i++)
            res[i] = cnt;
        cnt++;
        p = nextp+c[cpos]-1;
        cpos++;
    }
    if(p+d < n+1) {cout << "NO" << endl;return 0;}
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
}
