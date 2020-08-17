#include<iostream>
using namespace std;

char g[110][110];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        s = "?"+s+"?";
        for(int j = 0; j <= m+1; j++)
        {
            g[i][j] = s[j];
        }
    }
    for(int i = 0; i <= m+1; i++) g[0][i] = g[n+1][i] = '?';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(g[i][j] == '*') cout << '*';
            else
            {
                int sums = 0;
                for(int k = 0; k < 8; k++)
                {
                    int x = i+dx[k], y = j+dy[k];
                    if(g[x][y] == '*') sums++;
                }
                cout << sums;
            }
        }
        cout << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    // fclose(stdout);
#endif
    return 0;
}