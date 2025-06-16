#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    int cnt = 1;
    int x = 0, y = 0;
    vector<int> dx = {-1, 1}, dy = {1, -1};
    int f = 0;
    while (cnt <= n*m) {
        cout << x << " " << y << " " << cnt << endl;
        g[x][y] = cnt++;
        x += dx[f];
        y += dy[f];
        if (x<0||y==m) {
            f ^= 1;
            if (x==-1) x = 0;
            if (y==m) y = m-1, x+=2;
        }
        if (x==n||y<0) {
            f ^= 1;
            if (x==n) x = n-1, y+=2;
            if (y==-1) y = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}