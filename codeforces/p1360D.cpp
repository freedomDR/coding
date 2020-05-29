#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b; cin >> a >> b;
        int need = 1e9;
        for(int i = 1; i*i <= a; i++)
        {
            if(a%i==0)
            {
                if(i <= b) need = min(need, a/i);
                if(a/i <= b) need = min(need, i);
            }
        }
        cout << need << endl;
    }
    return 0;
}