#include <iostream>
#include <algorithm>

const int maxn = 1e6+10;

int a[maxn];
long long suf[maxn];
int n;
using namespace std;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n, [](int i, int j) {return i > j;});
    for(int i = 1; i <= n; i++) suf[i] = suf[i-1]+a[i];
    long long ans = 0;
    int x, y; cin >> x >> y;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= y; j++)
        {
            ans += suf[i*j];
        }
    }
    cout << ans << endl;
    return 0;
}