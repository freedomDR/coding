#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long a,b,n,s;
        cin >> a >> b >> n >> s;
        if(a*n + b < s) cout << "NO" << endl;
        else if(a*n <= s) cout << "YES" << endl;
        else if(s%n <= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
