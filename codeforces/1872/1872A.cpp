#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    int a, b, c;
    while(t--)
    {
        cin >> a >> b >> c;
        double mid = (a+b)/2.0;
        cout << std::ceil(abs(a-mid)*1.0/c) << endl;
    }
    return 0;
}
