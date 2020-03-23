#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> b(n), a(n), x(n+5);
    for(auto &it:b) cin >> it;
    a[0] = b[0];
    x[0] = 0;
    int tmp = b[0];
    x[1] = a[0];
    for(int i = 1; i < n; i++)
    {
        a[i] = b[i]+x[i];
        tmp = max(tmp, a[i]);
        x[i+1] = tmp;
    }
    for(auto &it:a)
        cout << it << " ";
    cout << endl;
    return 0;
}