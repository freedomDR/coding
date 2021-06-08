#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1010;

int c[N][N];

int main()
{
    #ifdef LOCAL
        freopen("luogu/p3397.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for(int j = 1; j <= m; j++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        c[x1][y1] += 1;
        c[x1][y2+1] -= 1;
        c[x2+1][y1] -= 1;
        c[x2+1][y2+1] += 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            c[i][j] += c[i-1][j]+c[i][j-1]-c[i-1][j-1];
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}