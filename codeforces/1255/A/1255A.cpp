#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> tmp = {0, 1, 1, 2, 2};
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(a == b) ans = 0;
        else if(a > b)
        {
            int remain = a-b;
            ans += remain/5;
            remain%=5;
            ans += tmp[remain];
        }else
        {
            int remain = b-a;
            ans += remain/5;
            remain%=5;
            ans += tmp[remain];
        }
        cout << ans << endl;
    }
    return 0;
}
