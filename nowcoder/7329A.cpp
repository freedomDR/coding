#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int v; cin >> v;
        double h = 0.5*v;
        double m = 6*v;
        h-=360*int(h/360);
        m-=360*int(m/360);
        int tmp1 = round(abs(h-m));
        int tmp2 = 360-tmp1;
        cout << min(tmp1, tmp2) << "\n"; 
    }
    return 0;
}