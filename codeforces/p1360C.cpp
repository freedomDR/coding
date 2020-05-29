#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(auto &v:a) cin >> v;
        bool ok = true;
        int odd = 0, even = 0;
        for(auto v:a)
        {
            if(v%2) odd++;
            else even++;
        }
        if(odd%2!=even%2) ok = false;
        else
        {
            if(odd%2!=0) 
            {
                sort(a.begin(), a.end());
                bool f = false;
                for(int i = 1; i < n; i++)
                {
                    if(a[i]-a[i-1] == 1) {f = true; break;}
                }
                if(!f) ok = false;
            }
        }
        cout << (ok?"YES":"NO") << endl;
    }
    return 0;
}