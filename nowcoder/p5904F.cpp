#include<bits/stdc++.h>

using namespace std;
int main()
{
    double a, b; cin >> a >> b;
    double ret = a/b/b;
    if(ret >= 18.5 && ret <= 23.9)
        cout << "Normal" << endl;
    else
        cout << "Abnormal" << endl;
    return 0;
}