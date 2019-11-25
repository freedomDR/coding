#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, pos = 0;
        cin >> n >> m;
        vector<pair<int, int>> a(n);
        for(auto &v:a)
        {
            cin >> v.first;
            v.second = ++pos;
        }
        if(m == 1 || m == 2 || m < n)
        {
            cout << "-1" << endl;
            continue;
        }
        sort(a.begin(),a.end());
        int sums = 0;
        for(auto &v:a) sums += v.first*2;
        sums += (a[0].first+a[1].first)*(m-n);
        cout << sums << endl;
        for(pos = 0; pos < n-1; pos++)
        {
            cout << a[pos].second << " " << a[pos+1].second << endl;
        }
        cout << a.back().second << " " << a[0].second << endl;
        for(pos = 0; pos < m-n; pos++)
        {
            cout << a[0].second << " " << a[1].second << endl;
        }
    }
    return 0;
}
