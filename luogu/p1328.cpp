#include<bits/stdc++.h>

using namespace std;

int j[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0}
};

int a[201], b[201];

int main()
{
    int n, na, nb;
    cin >> n >> na >> nb;
    for(int i = 0; i < na; i++) cin >> a[i];
    for(int i = 0; i < nb; i++) cin >> b[i];
    int aa = 0, bb = 0;
    for(int i = 0; i < n; i++)
    {
        if(j[a[i%na]][b[i%nb]] == 1) aa++;
        else if(j[a[i%na]][b[i%nb]] == -1) bb++;
    }
    cout << aa << ' ' << bb << endl;
    return 0;
}
