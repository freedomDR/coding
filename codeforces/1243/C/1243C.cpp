#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n; cin >> n;
    vector<long long> d;
    bool odd = false;
    for(long long i = 2; i*i <= n; i++)
    {
        if(n%i == 0) d.push_back(i);
        if(n%i == 0 && i != n/i) d.push_back(n/i); 
        if(n%i == 0 && (i%2 == 1 || (n/i)%2 == 1)) odd = true;
    }
    if(d.size() == 0) cout << n << endl;
    else if(d.size() == 1) cout << d.back() << endl;
    else if(odd)cout << 1 << endl;
    else cout << 2 << endl;
}
