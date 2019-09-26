#include<bits/stdc++.h>
using namespace std;
int p[100001];
int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < q; i++)
    {
        int pos; cin >> pos;
        p[pos]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(p[i]+k-q > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
