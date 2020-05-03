#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        set<int> s;
        for(int i = 1; i <= n; i++)
        {
            int v;
            cin >> v;
            s.insert(v);
        }
        if(s.size()>k) {cout << "-1" << endl;}
        else
        {
            cout << (k*n) << endl;
            for(int i = 0; i < n; i++)
            {
                for(auto j:s) cout << j << " ";
                for(int j = k-s.size(), v = 1; j > 0;v++)
                {
                    if(s.count(v)==0) {cout << v << " "; j--;}
                }
            }
            cout << endl;
        }
    }
    return 0;
}