#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(n%3 != 1)
        {
            for(int i = 1; i <= n/3; i++)
                cout << "21";
            if(n%3 == 2)
                cout << "2";
        }else 
        {
            for(int i = 1; i <= n/3; i++)
                cout << "12";
            cout << "1";
        }
        cout << endl;
    }
    return 0;
}