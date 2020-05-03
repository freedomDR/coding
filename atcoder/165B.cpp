#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    int ans = 0;
    long long a = 100;
    while(a<x)
    {
        a = a+(a/100);
        ans++;
    }
    cout << ans << endl;
    return 0;
}