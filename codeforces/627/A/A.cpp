#include <bits/stdc++.h>

using namespace std;
int t, n, odds, evens;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        odds = evens = 0;
        for(int i = 1; i <= n; i++)
        {
            int v;
            cin >> v;
            if(v%2) odds++;
            else evens++;
        }       
        if(odds == 0 || evens == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
    return 0;
}