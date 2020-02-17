#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        ans = min(min(a, b), c);
        a -= ans;
        b -= ans;
        c -= ans;
        if(c == 0)
        {
            if(a == b)
            {
                ans+=(a+1)/2;
            }
            else
            {

                int tmp = min(abs(a-b), min(a,b));
                ans += tmp;
                if(a > b)
                {
                    a -= 2*tmp;
                    b -= tmp;
                }
                else
                {
                    a -= tmp;
                    b-= 2*tmp;
                }
                ans += (min(a, b)+1)/2;
            }

        }
        cout << ans << endl;
    }
    return 0;
}
