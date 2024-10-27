#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--) 
    {
        int x;
        cin >> x;
        long long sums_v = 0, v = 0, max_v = 0, ans = 0;
        for(int i = 0; i < x; i++)
        {
            cin >> v;
            max_v = max(v, max_v);
            sums_v += v;
            if(sums_v == max_v*2)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}