#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    int c1 = 0, c2 = 0;
    for(int i = 1; i <= n; i++)
    {
        int v; cin >> v;
        if(v>0) c1++;
        if(v<0) c2++;
    }
    cout << "positive:" << c1 << endl;
    cout << "negative:" << c2 << endl;
    return 0;
}