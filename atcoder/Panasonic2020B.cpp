#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long h, w;
    cin >> h >> w;
    long long ans = 0;
    ans += (h/2)*w;
    if(h%2)
    {
        ans += (w-1)/2 +1;
    }
    cout << ans << endl;
    return 0;
}