#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> dx = {-1, 1}, dy = {1, -1};
    int x = 0, y = 0;
    int val = 1;
    vector<vector<int>> g(n, vector<int>(m, 0));
    int pos = 0;
    while (val <= n*m) {
        g[x][y] = val++;
        x += dx[pos];
        y += dy[pos];
        if (x==-1&&y==m) {
            pos ^= 1;
            x = 1;
            y = m-1;
        }
        if (x==n&&y==-1) {
            pos ^= 1;
            x = n-1;
            y = 1;
        }
        if (x==-1) {
            pos ^= 1;
            x = 0;
        }
        if (x==n) {
            pos ^= 1;
            x = n-1;
            y+=2;
        }
        if (y==-1) {
            pos ^= 1;
            y = 0;
        }
        if (y==m) {
            pos ^= 1;
            y = m-1;
            x += 2;
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