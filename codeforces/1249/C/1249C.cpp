#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q; cin >> q;
    while(q--)
    {
        long long n, base = 3, ans = 0;
        vector<int> b(64);
        int pos = 1;
        cin >> n;
        while(n >= 3)
        {
            if(n)
            if(n%base == 0) b[pos] = 1;
            pos++;
            base *= 3;
            n -= base;
        }
        cout << min(ans+1, n) << endl;
    }
    return 0;
}

