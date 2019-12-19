#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    if(r == 1 && c == 1)
    {
        cout << "0" << endl;
    }else if(r == 1 || c == 1)
    {
        int val = 2;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
                cout << val++ << " ";
            cout << endl;
        }
    }else
    {
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
                cout << i*(j+r) << " ";
            cout << endl;
        }
    }
    return 0;
}
