#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n), res;
        for(auto &v:a) cin >> v;
        int st = 0, minp = 0;
        while(st != n)
        {
            for(int i = st; i < n; i++)
            {
                if(a[minp] > a[i]) minp = i;
            }
            res.push_back(a[minp]);
            for(int i = st; i < minp; i++)
            {
                res.push_back(a[i]);
            }
            if(minp == st) {st++;minp++;}
            else {a[minp] = a[minp-1];st = minp;res.pop_back();}
        }
        for(auto v:res) cout << v << " ";
        cout << endl;
    }
    return 0;
}
