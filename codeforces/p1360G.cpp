#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if(n*a != m*b) {cout << "NO" << endl;}
        else
        {
            cout << "YES" << endl;
            int p = 0;
            for(int i = 0; i < n; i++)
            {
                string s(m, '0');
                for(int j = 0; j < a; j++)
                {
                    s[p++] = '1';
                    if(p == m) p = 0;
                }
                cout << s << endl;
            } 
        }
        
    }
    return 0;
}