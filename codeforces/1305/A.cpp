#include<bits/stdc++.h>
using namespace std;
int t, n, a[110], b[110];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a, a+n);
        sort(b, b+n);
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        for(int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}