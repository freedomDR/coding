#include<bits/stdc++.h>
using namespace std;
long long M[1010][1010], ans[1010];
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> M[i][j];
    ans[2] = (long long)sqrt(M[1][2]*M[2][n]/M[1][n]);
    ans[1] = M[1][2]/ans[2];
    for(int i = 3; i <= n; i++)
        ans[i] = M[1][i] / ans[1];
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}

