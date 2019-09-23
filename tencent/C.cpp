#include<bits/stdc++.h>
using namespace std;
int x[110];
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i];
        sort(x, x+n);
        int a = 0, b = 0, pos = n-1, as = 0, bs = 0;
        while(pos >= 0)
        {
            if(as == (n+1)/2) {b += x[pos--];bs++;continue;}
            if(bs == (n+1)/2) {a += x[pos--];as++;continue;}
            if(a < b)
            {
                a +=x[pos--];
                as++;
            }
            else
            {
                b += x[pos--];
                bs++;
            }

        }
        if(pos == 0)
        {
            if(a < b) a += x[pos];
            else b += x[pos];
        }
        cout << min(a, b) << " " << max(a, b) << endl;
    }
    return 0;
}
