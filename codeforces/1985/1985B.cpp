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
        int max_s = 0, max_v = 0;
        for(int i = 2; i <= x; i++)
        {
            int k = x/i;
            int max_ss = (1+k)*k/2 * i;
            if(max_ss > max_s) 
            {
                max_s = max_ss;
                max_v = i;
            }
        }
        cout << max_v << endl;
    }
    return 0;
}