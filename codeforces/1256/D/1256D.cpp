#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q; cin >> q;
    while(q--)
    {
        long long n, k, lone = 0, p = 0;
        string s;
        cin >> n >> k;
        cin >> s;
        while(lone < n && s[lone] == '0') lone++;
        p = lone;
        while(k > 0)
        {
            while(lone < n && s[lone] == '0') lone++;
            if(lone == n) break;
            while(p < n && s[p] == '1') p++;
            if(p == n) break;
            int need = p-lone;
            if(need < k)
            {
                k -= need;
                s[p] = '1';
                s[lone] = '0';
            }else
            {
                s[p] = '1';
                s[p-k] = '0';
                k = 0;
            }
        }
        cout << s << endl;
    }
    return 0;
}
