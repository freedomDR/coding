#include<bits/stdc++.h>

using namespace std;

int g[21][21][21], w, x, h, q;

int main()
{
    cin >> w >> x >> h >> q;
    while(q--)
    {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                for(int k = z1; k <= z2; k++)
                    g[i][j][k] = 1;
    }
    int sums = 0;
    for(int i = 1; i <= w; i++)
        for(int j = 1; j <= x; j++)
            for(int k = 1; k <= h; k++)
                if(!g[i][j][k]) sums++;
    cout << sums << endl;
    return 0;
}
