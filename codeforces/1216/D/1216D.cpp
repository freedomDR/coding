#include<bits/stdc++.h>
using namespace std;
long long a[200500];
int main()
{
    int n;
    long long max_a = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    long long t = 0, ys = 0;
    for(int i = 0; i < n; i++)
    {
        if(max_a == a[i]) continue;
        ys += max_a-a[i];
        t = __gcd(t, max_a-a[i]);
    }
    cout << ys/t << " " << t << endl;
}
