#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    vector<int> f(4, -1);
    f[x%4] = 0;
    f[(x+1)%4] = 1;
    f[(x+2)%4] = 2;
    if(f[1] != -1) {
        cout << f[1] <<" "<<"A"<<endl;
        return 0;
    }
    if(f[3] != -1) {
        cout << f[3] <<" "<<"B"<<endl;
        return 0;
    }
    if(f[2] != -1) {
        cout << f[2] <<" "<<"C"<<endl;
        return 0;
    }
    if(f[0] != -1) {
        cout << f[0] <<" "<<"D"<<endl;
        return 0;
    }
    return 0;
}
