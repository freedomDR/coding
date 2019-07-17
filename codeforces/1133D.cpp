#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    map<pair<int, int>, int> ans;
    int two_zero = 0;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
        if(a[i] == 0)
        {
            if(b[i] == 0) two_zero++;
            continue;
        }
        if(a[i] < 0) a[i]*=-1, b[i]*=-1;
        int tmp = gcd(abs(a[i]), abs(b[i]));
        ans[make_pair(a[i]/tmp, b[i]/tmp)]++;

    }
    int sums = 0;
    for(auto i : ans) sums = max(sums, i.second);
    cout<<sums+two_zero<<endl;
    return 0;
}
