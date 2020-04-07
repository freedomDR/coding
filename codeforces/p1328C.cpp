#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string x, a, b;
        cin >> x;
        a = string(n, '1');
        b = string(n, '1');
        int f = 0;
        for(int i = 1; i < n; i++)
        {
            if(f==0)
            {
                if(x[i]=='2') {a[i] = '1';b[i] = '1';}
                else if(x[i]=='0') {a[i] = '0'; b[i] = '0';}
                else {a[i] = '1'; b[i] = '0';f=1;}
            }
            else
            {
                a[i] = '0';
                b[i] = x[i];
            }
        }
        cout << a << endl << b << endl;
    }
    return 0;
}