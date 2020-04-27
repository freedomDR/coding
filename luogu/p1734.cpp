#include<bits/stdc++.h>

using namespace std;

int a[1001], f[1001], n;
void pre()
{
    for(int i = 1; i < 1001; i++)
        for(int j = i+i; j < 1001; j+=i)
            a[j] += i;
}
int main()
{
    pre();
    cin >> n;
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = n; j >= i; j--)
            f[j] = max(f[j], f[j-i]+a[i]);
    }
    cout << f[n] << endl;
    return 0;
}