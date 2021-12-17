#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(n%2==0)
        {
            int a,b,c;
            c = 1;
            a = (n-1)/2;
            b = a+1;
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            int a, b, c;
            c = 1;
            a = (n-1)/2 + 1;
            b = (n-1)/2 - 1;
            if(a%2 == 0) {a++;b--;}
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}
