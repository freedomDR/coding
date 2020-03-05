#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, sums = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int v; cin >> v;
            sums += v;
        }
        cout << min(m, sums) << endl;
    }
}