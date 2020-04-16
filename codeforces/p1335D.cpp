#include<bits/stdc++.h>

using namespace std;

int g[10][10];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(g, 0, sizeof g);
        for(int i = 1; i < 10; i++)
        {
            string s;
            cin >> s;
            for(int j = 1; j < 10; j++)
            {
                g[i][j] = s[j-1]-'0';
            }
        }
        if(g[1][1]!=5) g[1][1] = 10-g[1][1];
        else g[1][1] = 1;
        if(g[2][4]!=5) g[2][4] = 10-g[2][4];
        else g[2][4] = 1;
        if(g[3][7] != 5) g[3][7] = 10-g[3][7];
        else g[3][7] = 1;
        if(g[4][2] != 5) g[4][2] = 10-g[4][2];
        else g[4][2] = 1;
        if(g[5][5] != 5) g[5][5] = 10-g[5][5];
        else g[5][5] = 1;
        if(g[6][8] != 5) g[6][8] = 10-g[6][8];
        else g[6][8] = 1;
        if(g[7][3] != 5) g[7][3] = 10-g[7][3];
        else g[7][3] = 1;
        if(g[8][6] != 5) g[8][6] = 10-g[8][6];
        else g[8][6] = 1;
        if(g[9][9] != 5) g[9][9] = 10-g[9][9];
        else g[9][9] = 1;
        for(int i = 1; i < 10; i++)
        {
            for(int j = 1; j < 10; j++)
                cout << g[i][j];
            cout << endl;
        }
    }
    return 0;
}