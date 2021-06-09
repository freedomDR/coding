#include<iostream>
#include<cstdio>

using namespace std;

const int N = 5010;

int a[N][N];
int n, m, x, y, v; 

int main()
{
    #ifdef LOCAL
        freopen("luogu/p2280.in", "r", stdin);
    #endif
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> v;
        x++; y++;
        a[x][y] = v;
    }
    int ans = 0;
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < N; j++)
        {
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if(i>=m&&j>=m)
                ans = max(ans, a[i][j]-a[i-m][j]-a[i][j-m]+a[i-m][j-m]);
        }
    }
    cout << ans;
    return 0;
}