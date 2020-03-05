#include<bits/stdc++.h>

using namespace std;

int a[1000010], b[1000010];
int n, m, p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) { cin >> a[i]; a[i] %= p;}
    for(int i = 0; i < m; i++) { cin >> b[i]; b[i] %= p;}
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i]%p) break;
    }
    for(j = 0; j < m; j++)
    {
        if(b[j]%p) break;
    }
    cout << i+j << endl;
    return 0;
}