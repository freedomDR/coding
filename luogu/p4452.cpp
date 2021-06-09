#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
long long a[N], b[N];

int main()
{
    #ifdef LOCAL
        freopen("./luogu/p4452.in", "r", stdin);
    #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i]-a[i-1];
    }
    long long pos = 0, neg = 0;
    for(int i = 2; i <= n; i++)
    {
        if(b[i]>0) pos += b[i];
        else neg -= b[i];
    }
    cout << max(pos, neg) << endl;
    cout << abs(pos-neg)+1 << endl;
    return 0;
}