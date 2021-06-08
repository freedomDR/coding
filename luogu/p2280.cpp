#include<iostream>
#include<cstdio>

using namespace std;

const int N = 10050;

int x[N][N];
int sums[N][N];

int main()
{
    #ifdef LOCAL
        freopen("luogu/p2280.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int xp, yp; cin >> xp >> yp;
        x[++xp][++yp] = m;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sums[i][j] = x[i][j]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
            int tmp = sums[i][j];
            if(i-m>=0) tmp-=sums[i-m][j];
            if(j-m>=0) tmp-=sums[i][j-m];
            if(i-m>=0&&j-m>=0) tmp+=sums[i-m][j-m];
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}