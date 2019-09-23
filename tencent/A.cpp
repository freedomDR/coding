#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int sums = 0, flag = 0;
        for(int i = 0; i < n; i++)
        {
            char v; cin >> v;
            if(v == '8') flag = 1;
            if(flag) sums++;
        }
        cout << (sums>=11?"YES":"NO") << endl;
    }
    return 0;
}
