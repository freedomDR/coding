#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for(auto &it:a) cin >> it;
        vector<int> cnt(64);
        for(auto it:a)
        {
            while(it>0)
            {
                long long base = 1;
                int i = 0;
                for(; base <= it; base *= k, i++);
                it -= (base/k);
                cnt[i-1]++;
            }
        }
        bool ok = true;
        for(auto it:cnt) if(it > 1) ok = false;
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}