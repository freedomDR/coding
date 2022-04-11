#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long a, b; cin >> a >> b;
        long long sums = a+b;
        for(int i = 0; i < 5; i++)
        {
            long long tmp; cin >> tmp;
            sums += tmp;
        }
        cout << a << " " << b << " " << (sums-(a+b)*4)/4 << endl;
    }
    return 0;
}
