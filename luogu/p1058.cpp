#include<bits/stdc++.h>

using namespace std;

int g[51][51], mm, nn, s[6]={2, 1, 0, 0, 0, 0}, e[6]={6, 6, 6, 6, 5, 4};

char gg[1000][1000];
char c[10][10]={
"..+---+",
"./   /|",
"+---+ |",
"|   | +",
"|   |/.",
"+---+..",
};

void fg(int x, int y)
{
    /* cout << x << " " << y << endl; */
    for(int i = 0; i < 6; i++)
    {
        for(int j = s[i]; j <= e[i]; j++)
        {
            int ii = x+(5-i), jj = y+j;
            gg[ii][jj] = c[i][j];
            mm = max(ii, mm);
            nn = max(jj, nn);
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < g[i][j]; k++)
            {
                fg((m-i-1)*2+3*k, (m-i-1)*2+4*j);
            }
        }
    }
    for(int i = mm; i >= 0; i--)
    {
        for(int j = 0; j <= nn; j++)
        {
            if(gg[i][j] == '\0') cout << '.';
            else cout << gg[i][j];
        }
        cout << endl;
    }
    return 0;
}
